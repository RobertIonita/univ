import { Component, AfterViewInit, ElementRef, ViewChild, OnInit } from '@angular/core';
import { MatCard } from '@angular/material/card';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.scss']
})

export class HomeComponent implements OnInit {

  homeTitle = 'Workspace';
  values = 10;
  multiplier = 5;
  randomsArr: number[] = [];
  constructor() {
    for (let i = 0; i < this.values; i++) {
      this.randomsArr.push(Math.floor(Math.random() * 100 + 1));
    }
  }
  ngOnInit(): void {
  }
}


