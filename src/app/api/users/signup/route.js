import User from '@/models/userModel'
import { NextResponse} from 'next/server';
import { dbConnect } from "@/dbConfig/dbComfig";
import bcrypt from "bcryptjs";

export async function POST(req) {
    try {
        await dbConnect();
        
        const reqBody = await req.json()
        const { username, email, password } = reqBody;
        
        if (!username || !email || !password) {
            return NextResponse.json(
                { error: "Please provide all required fields" }, 
                { status: 400 }
            );
        }
        
        console.log("Signup request:", { username, email });

        const user = await User.findOne({ email })

        if (user) {
            return NextResponse.json(
                { error: "User already exists" }, 
                { status: 400 }
            );
        }
        
        // Hash password
        const salt = await bcrypt.genSalt(10);
        const hashedPassword = await bcrypt.hash(password, salt)

        const newUser = new User({
            username,
            email,
            password: hashedPassword
        })

        const savedUser = await newUser.save()
        console.log("User created:", savedUser._id);
        
        return NextResponse.json(
            { 
                message: "User created successfully", 
                success: true, 
                userId: savedUser
            }, 
            { status: 201 }
        );

    } catch (error) {
        console.error("Signup error:", error);
        return NextResponse.json(
            { error: error.message || "Internal server error" }, 
            { status: 500 }
        );
    }
}