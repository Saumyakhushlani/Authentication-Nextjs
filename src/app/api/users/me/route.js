import User from '@/models/userModel'
import { NextResponse } from 'next/server';
import { dbConnect } from "@/dbConfig/dbComfig";
import { getDataFromToken } from '@/helpers/getDatafromToken';

dbConnect()
export async function GET(request) {
    try {
        
        const userId = await getDataFromToken(request)
        
        const user = await User.findOne({ _id: userId }).select("-password")
        return NextResponse.json(
            {
                message: "User Found",
                data: user
            }
        )

    } catch (error) {
        return NextResponse.json(
            { error: error.message },
            { status: 404 }
        )
    }
}