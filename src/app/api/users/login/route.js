import User from '@/models/userModel'
import { NextResponse } from 'next/server';
import { dbConnect } from "@/dbConfig/dbComfig";
import bcrypt from "bcryptjs";
import jwt from 'jsonwebtoken'

export async function POST(req) {
    try {
        await dbConnect();

        const reqBody = await req.json();
        const { email, password } = reqBody

        //Checking if user already exits
        const user = await User.findOne({ email })
        if (!user) {
            return NextResponse.json(
                { error: "User does not exists" },
                { status: 400 }
            )
        }

        //check password is correct
        const validPassword = await bcrypt.compare(password, user.password)
        if (!validPassword) {
            return NextResponse(
                { error: "Password is Incorrect" },
                { status: 400 }
            )
        }

        //create token data
        const tokenData = {
            id: user._id,
            username: user.username,
            email: user.email
        }
        //create token now
        const token = await jwt.sign(tokenData, process.env.TOKEN_SECRET, { expiresIn: "1d" })

        //creating response
        const response = NextResponse.json(
            {message:"User login succesfully",sucess:true},
            {ststus:200},
            
        )
        response.cookies.set("token",token,{
            httpOnly:true,
            
        })
        return response


    } catch (error) {
        console.log("Login Error :", error);
        return NextResponse.json(
            { error: error.message || 'Internal server error' },
            { status: 404 }
        )
    }

}