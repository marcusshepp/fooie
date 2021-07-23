import { HttpClient } from '@angular/common/http';
import { EventEmitter, Injectable } from '@angular/core';
import * as SignalR from '@aspnet/signalr';
import { SignalRequest, SignalResponse } from '../models/signals';

@Injectable({
  providedIn: 'root'
})
export class SignalRService {

  public signalReceieved: EventEmitter<SignalResponse> = new EventEmitter<SignalResponse>();

  private hubConnection!: SignalR.HubConnection;


  constructor(
    private http: HttpClient,
  ) {
    this.buildConnection();
    this.startConnection();
  }

  public buildConnection() {
    this.hubConnection = new SignalR.HubConnectionBuilder().withUrl("https://localhost:44300/chatHub").build();
    console.log('hubCOnnection', this.hubConnection);
  }

  public startConnection() {
    this.hubConnection.start()
    .then((data) => {
      console.log("Connection Started", data);
      this.registerSignalEvents();
    })
    .catch(err => {
      console.log("Error while starting connection: " + err);
      setTimeout(() => this.startConnection(), 3000);
    });
  }

  public sendMessage(request: SignalRequest): void {
    // this.http.get("https://localhost:44300/api/chat/deliverypoint").subscribe();
    // this.http.get("https://localhost:44300/chatHub").subscribe();
    this.hubConnection.invoke("send", request)
      .then((data) => {
        console.log('send succ', data);
      })
      .catch((data) => {
        console.log('err while trying to send', data);
      });
  }

  private registerSignalEvents() {
    this.hubConnection.on("RM", (data) => {
      console.log("message receieved", data);
      this.signalReceieved.emit(data);
    });
  }
}

