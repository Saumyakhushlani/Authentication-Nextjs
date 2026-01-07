import mongoose from "mongoose";

export async function dbConnect (){
    try {
        await mongoose.connect(process.env.MONGO_URI!)
        const connection =mongoose.connection;
        
        connection.on('connected',()=>{
            console.log("Mongodb Connected Succesfully!")
        })

        connection.on('error',(err)=>{
            console.log("Error in connecting mongodb",err);
            process.exit();
        })

    } catch (error) {
        console.log("DB not connected. Error :",error);
        process.exit(1);
        
    }
}