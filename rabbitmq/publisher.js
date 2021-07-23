const amqp = require("amqplib");

const msg = {number: 90};
async function connect() {
    const connection = await amqp.connect("amqp://localhost:5672");
    const channel = await connection.createChannel();
    const result = await channel.assertQueue("demo-queue");
    
    setInterval(() => {
        channel.sendToQueue("demo-queue", Buffer.from(JSON.stringify(msg)));
        console.log("sent job", `${JSON.stringify(msg)}`);
    }, 200)

}

connect();