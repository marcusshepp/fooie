import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormControl, FormGroup, Validators } from '@angular/forms';
import { SignalRequest, SignalResponse } from './models/signals';
import { SignalRService } from './services/signal-r.service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent implements OnInit {
  public signalList: SignalResponse[] = [];
  public form!: FormGroup;
  public message: FormControl = new FormControl(null, [Validators.required]);


  constructor(
    private signalService: SignalRService,
    private fb: FormBuilder,
  ) {}

  public ngOnInit(): void {
    this.signalService.signalReceieved.subscribe((response: SignalResponse): void => {
      this.signalList.push(response);
    });

    this.form = this.fb.group({
      message: this.message,
    });
  }

  public send(): void {
    const message = this.message.value;
    this.signalService.sendMessage({ message });
    this.message.setValue(null);
  }

}
