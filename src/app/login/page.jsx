"use client"
import React, { useEffect } from 'react'
import Link from 'next/link'
import { useRouter } from 'next/navigation'
import axios from 'axios'
import { useState } from 'react'
import toast from 'react-hot-toast'

const page = () => {
  const router = useRouter()
  const [user, setUser] = useState({
    email: "",
    password: "",
  })
  const [buttonDisabled, setbuttonDisabled] = useState(false)
  const [loading, setLoading] = useState(false)
  useEffect(() => {
    if (user.email.length > 0 && user.password.length > 0) {
      setbuttonDisabled(false)
    }
    else {
      setbuttonDisabled(true)
    }
  }, [user])

  const onLogin = async () => {
    try {
      setLoading(true)
      const response = await axios.post("/api/users/login",user)
      console.log("login succesfull",response.data)
      toast.success("Login Success");
      router.push("/profile")
      
    } catch (error) {
      console.log("Login Failed! ", error)
      toast.error(error.message)
    } finally {
      setLoading(false)
    }
  }

  return (
    <div className='flex flex-col items-center justify-center min-h-screen py-2'>
      <h1 className='text-4xl mb-4 font-semibold'>{loading ? "Processing" : "Login"}</h1>



      <label htmlFor="email">Email</label>
      <input
        className='p-2 rounded-xl mx-4 mb-4 text-black bg-white'
        id='email'
        type="text"
        value={user.email}
        onChange={(e) => setUser({ ...user, email: e.target.value })}
        placeholder='Email'
      />

      <label htmlFor="password">password</label>
      <input
        className='p-2 rounded-xl mx-4 mb-4 text-black bg-white'
        id='password'
        type="password"
        value={user.password}
        onChange={(e) => setUser({ ...user, password: e.target.value })}
        placeholder='Password'
      />

      <button className='bg-blue-600 p-2 my-2 rounded-2xl px-10 hover:cursor-pointer hover:bg-blue-450' onClick={onLogin}>{buttonDisabled ? "Fill details" : "Login"}</button>
      <Link href='/signup'>Redirect to SignUp page</Link>
    </div>
  )
}

export default page
