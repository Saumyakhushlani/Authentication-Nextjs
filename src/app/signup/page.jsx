"use client"
import React, { useEffect } from 'react'
import Link from 'next/link'
import { useRouter } from 'next/navigation'
import axios from 'axios'
import { useState } from 'react'
import toast from 'react-hot-toast'

const page = () => {
  const router = useRouter();
  const [user, setUser] = useState({
    email: "",
    password: "",
    username: ""
  })
  const [buttonDisabled, setbuttonDisabled] = useState(false)
  const [loading, setLoading] = useState(false)

  useEffect(() => {
    if (user.email.length > 0 && user.password.length > 0 && user.username.length > 0) {
      setbuttonDisabled(false)
    }
    else {
      setbuttonDisabled(true)
    }
  }, [user]);

  const onSignup = async () => {
    try {
      setLoading(true);
      const response = await axios.post("/api/users/signup", user)
      console.log("SignUp succesful ",response.data)
      router.push(" /login")
    } catch (error) {
      console.log("Signup Failed! Error:", error.message)
      toast.error(error.message);
    } finally {
      setLoading(false)
    }
  }

  return (
    <div className='flex flex-col items-center justify-center min-h-screen py-2'>
      <h1 className='text-4xl mb-4 font-semibold'>{loading ? "Processing" : "Signup"}</h1>

      <label htmlFor="username">Username</label>
      <input
        className='p-2 rounded-xl mx-4 mb-4 text-black bg-white'
        id='username'
        type="text"
        value={user.username}
        onChange={(e) => setUser({ ...user, username: e.target.value })}
        placeholder='Username'
      />

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

      <button className='bg-blue-600 p-2 my-2 rounded-2xl px-10 hover:cursor-pointer hover:bg-blue-450' onClick={onSignup}>{buttonDisabled ? "Fill Details" : "Sign Up"}</button>
      <Link href='/login'>Redirect to Login page</Link>
    </div>
  )
}

export default page
