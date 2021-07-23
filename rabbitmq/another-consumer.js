const amqp = require("amqplib");

const msg = {number: 90};
async function connect() {
    const connection = await amqp.connect("amqp://localhost:5672");
    const channel = await connection.createChannel();
    const result = await channel.assertQueue("DA_Logging");
    // console.log("sent job", `${JSON.stringify(msg)}`);
    // console.log("result", `${JSON.stringify(result)}`);
    setInterval(() => {
        channel.consume("DA_Logging", message => {
            console.log('anther consumtion: ', message.content.toString());
        });
        console.log("\n");
    }, 2000)
}

connect();