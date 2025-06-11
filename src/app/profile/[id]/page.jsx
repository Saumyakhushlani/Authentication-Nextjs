import React from 'react'

const page = ({params}) => {
  return (
    <div className='flex flex-col justify-center items-center py-2 min-h-screen'>
        <h1 className='text-5xl text-white mb-4'>Profile</h1>
        <div>Profile page</div>
        <span className='text-gray-300'>{params.id}</span>
    </div>
  )
}

export default page
