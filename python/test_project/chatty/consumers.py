from channels import Group 
from channels.sessions import channel_session


@channel_session
def ws_connect(message):
    # work out room name from path (ignore slashes) 
    print "adding client to group: chat"
    room = message.content["path"].strip("/")
    message.channel_session["room"] = room
    Group("chat-{}".format(room)).add(message.reply_channel)

@channel_session
def ws_message(message):
    print "sending message to group: chat"
    if message.channel_session.get("room", None):
        Group("chat-{}".format(message.channel_session["room"])).send({
            "text": "{0}".format(message["text"]),
        })

@channel_session
def ws_disconnect(message):
    print "disconnecting client from group: chat"
    # connect to websocket.disconnect
    Group("chat-{}".format(message.channel_session["room"])).discard(message.reply_channel)


