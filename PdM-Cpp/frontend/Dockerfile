FROM node:14

WORKDIR /app

# Copy package files and install dependencies
COPY package*.json ./
RUN npm install

# Copy the rest of the front end source code
COPY . .

EXPOSE 3000

# For a React app created with create-react-app:
CMD ["npm", "start"]
