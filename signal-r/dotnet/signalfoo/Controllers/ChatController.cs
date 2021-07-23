using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.SignalR;


namespace SignalFoo.Controllers
{
    [Route("api/[controller]")]
    public class ChatController : Controller
    {

        private readonly IHubContext<ChatHub> _hubContext;

        public ChatController(IHubContext<ChatHub> hubContext )
        {
            _hubContext = hubContext;
        }

        public class SignalRequest
        {
            public string Message { get; set; }
            public string Name { get; set; }
        }

        public class SignalResponse
        {
            public string Message { get; set; }
        }


        [HttpGet]
        [Route("DeliveryPoint")]
        [ProducesResponseType(404)]
        [ProducesResponseType(200, Type = typeof(bool))]
        public async Task<ActionResult> SignalArrived()
        {
            var foo = new SignalResponse
            {
                Message = "Response Message"
            };
            await _hubContext.Clients.All.SendAsync("Send", "foo", "bar");
            return StatusCode(200);
        }

        //[HttpPost]
        //[Route("")]
        //public async Task<ActionResult> Chat(SignalRequest request)
        //{
        //    var foo = _hubContext.Clients.User();
        //}
    }
}
