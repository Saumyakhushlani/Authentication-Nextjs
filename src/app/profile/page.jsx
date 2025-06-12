"use client"
import React from 'react'
import axios from 'axios'
import toast from 'react-hot-toast'

import { useRouter } from 'next/navigation'

const page = () => {
  const router = useRouter();
  const logout2 = async () => {
    console.log("BUTTON CLICKED")
    try {
      
      const response = await axios.get("/api/users/logout")
      console.log("logout succesfull", response.data)
      toast.success("Logout Success");
      router.push("/login")
    } catch (error) {
      console.log("Error in api call", error)
    }

  }
  return (
    <div className='flex flex-col justify-center items-center py-2 min-h-screen'>
      <h1 className='text-5xl text-white mb-4'>Profile</h1>
      <div className='mb-4 text-lg'>Profile page</div>
      <button className='px-4 py-2 bg-red-600 text-white text-lg rounded-2xl cursor-pointer' onClick={logout2}>Logout</button>
    </div>
  )
}

export default page
