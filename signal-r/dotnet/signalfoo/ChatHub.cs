using Microsoft.AspNetCore.SignalR;
using static SignalFoo.Controllers.ChatController;

namespace SignalFoo
{
    public class ChatHub : Hub
    {
        public void Send(SignalRequest request)
        {
            //Clients.All.SendAsync("RM", name, message);
            Clients.AllExcept(Context.ConnectionId).SendAsync("RM", request);
        }

    }
}