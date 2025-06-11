import User from '@/models/userModel'
import { NextResponse, NextRequest } from 'next/server';
import { dbConnect } from "@/dbConfig/dbComfig";
import bcrypt from "bcryptjs";
import { errorMonitor } from 'events';

dbConnect();

export async function POST(req) {
    try {
        const reqBody = await req.json()
        const { username, email, password } = reqBody;
        console.log(reqBody)

        const user = await User.findOne({email})

        if(user){
            return NextResponse.json({status:400},{message:"User already Exists"})
        }
        //hashed password
        const salt = await bcrypt.genSalt(10);
        const hashedPassword = await bcrypt.hash(password,salt)

    } catch (error) {
        return NextResponse.json({ error: error.message }, { status: 500 })
    }
}
