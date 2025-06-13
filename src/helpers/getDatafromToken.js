import jwt from 'jsonwebtoken';

export const getDataFromToken = async (request) => {
    try {
        const token = request.cookies.get('token')?.value || '';
        if (!token) {
            console.log("No token found.");
            return null;
        }

        const decoded = await jwt.verify(token, process.env.TOKEN_SECRET);
        return decoded.id;
    } catch (error) {
        console.log("Error in getting data from token", error.message);
        return null;
    }
};

