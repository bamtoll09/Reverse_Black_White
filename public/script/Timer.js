minuit = 0;
second = 10;

function BeforeGameSet(){
    TimerBox = document.getElementById("timeBox");
    if(second > 0) second--;
    else{
        clearInterval(BeforeTimer);
        AfterTimer = setInterval(Timer, 1000);
    }
    
    TimerSet();
}

function Timer(){
    if(second < 60){
        second++;
    }
    if(second >= 60){
        minuit++;
        second = 0;
    }
    
    TimerSet();
}

function TimerSet(){
    if(minuit < 10 && second < 10){
        TimerBox.innerHTML = "0" + minuit + " : 0" + second;
    }
    else if(minuit < 10){
        TimerBox.innerHTML = "0" + minuit + " : " + second;
    }
    else if(second < 10){
        TimerBox.innerHTML = minuit + " : 0" + second;
    }
    else{
        TimerBox.innerHTML = minuit + " : " + second;
    }
}