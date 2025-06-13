"use client"
import React, { useState } from 'react'
import axios from 'axios'
import toast from 'react-hot-toast'

import { useRouter } from 'next/navigation'
import Link from 'next/link'

const page = () => {
  const router = useRouter();
  const[data,setData]=useState('nothing')

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

  const getUserDetail = async()=>{
    try {
      const response =await axios.get('/api/users/me');
      console.log(response.data);
      setData(response.data.data._id)
    } catch (error) {
      console.log("Error in getting user Detail",error.message)
    }
  }
  return (
    <div className='flex flex-col justify-center items-center py-2 min-h-screen'>
      <h1 className='text-5xl text-white mb-4'>Profile</h1>
      <div className='mb-4 text-lg '>Profile page</div>
      <h2 className='text-white mb-2 bg-amber-400'>{data=='nothing'?"":<Link href={`/profile/${data}`}> User details</Link>}</h2>
      <button className='px-4 mb-2 py-2 bg-red-600 text-white text-lg rounded-2xl cursor-pointer' onClick={logout2}>Logout</button>
      <button className='px-4 py-2 bg-emerald-600 text-white text-lg rounded-2xl cursor-pointer' onClick={getUserDetail}>Get user Details</button>
    </div>
  )
}

export default page
