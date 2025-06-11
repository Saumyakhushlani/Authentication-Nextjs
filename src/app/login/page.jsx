"use client"
import React from 'react'
import Link from 'next/link'
import { useRouter } from 'next/navigation'
import axios from 'axios'
import { useState } from 'react'

const page = () => {
  const [user, setUser] = useState({
    email: "",
    password: "",
  })

  const onLogin = async () => {
    console.log(user)
  }

  return (
    <div className='flex flex-col items-center justify-center min-h-screen py-2'>
      <h1 className='text-4xl mb-4 font-semibold'>Login</h1>

      

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

      <button className='bg-blue-600 p-2 my-2 rounded-2xl px-10 hover:cursor-pointer hover:bg-blue-450' onClick={onLogin}>Login</button>
      <Link href='/signup'>Redirect to SignUp page</Link>
    </div>
  )
}

export default page
