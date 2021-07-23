const amqp = require("amqplib");

async function connect() {
    const connection = await amqp.connect("amqp://guest:guest@localhost:5672");
    const channel = await connection.createChannel();
    
    const result = await channel.assertQueue("DA_Queue");
    channel.consume("DA_Queue", message => {
        console.log('consuming job: ', message.content.toString());
    });

}

connect();