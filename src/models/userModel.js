import mongoose, { Schema } from "mongoose";

const userSchema = new Schema({
    username: {
        type: String,
        required: [true, "Please provide a username"],
        unique: true
    },
    emai: {
        type: String,
        required: [true, "Please provide an Email"],
        unique: true
    },
    password: {
        type: String,
        required: [true, "Please provide a password"]
    },
    isVerified: {
        type: Boolean,
        default: false
    },
    isAdmin: {
        type: Boolean,
        default: false
    },
    forgotPasswordToken:String,
    forgotPasswordExpiry:Date,
    verifiedToken:String,
    verifiedTokenExpiry:Date
})

const User = mongoose.models.users || mongoose.model("User", userSchema);

export default User