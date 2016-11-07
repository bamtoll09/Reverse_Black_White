class Enemy{
    constructor(){
        PlayerImageArr.push("../resource/image/Enemy/Monster_B_Down.png");
        this.enemyObj = document.createElement('img');
        this.enemyObj.src = PlayerImageArr[0];
        this.enemyObj.className = "Enemy";
        this.moveCount = 0;
        this.canMove = true;
        //this.EnemyX = PlayerXMovedArr[0];
        //this.EnemyY = PlayerYMovedArr[0];
        if(mapBoxArr[PlayerYMovedArr[this.moveCount]][PlayerXMovedArr[this.moveCount]].innerHTML.indexOf("Player") != -1){
            gameover();
        }
        
        mapBoxArr[PlayerYMovedArr[this.moveCount]][PlayerXMovedArr[this.moveCount]].appendChild(this.enemyObj);
    }
    
    moving(){
        this.canMove = false;
        this.enemyObj.src = PlayerImageArr[this.moveCount];
        
        if(PlayerXMovedArr[this.moveCount] - PlayerXMovedArr[this.moveCount + 1] == -1){
            this.enemyObj.style.left = "25px";
            setTimeout(this.movingF, 280, this);
        }
        else if(PlayerXMovedArr[this.moveCount] - PlayerXMovedArr[this.moveCount + 1] == 1){
            this.enemyObj.style.left = "-25px";
            setTimeout(this.movingF, 280, this);
        }
        else if(PlayerYMovedArr[this.moveCount] - PlayerYMovedArr[this.moveCount + 1] == -1){
            this.enemyObj.style.top = "25px";
            setTimeout(this.movingF, 280, this);
        }
        else if(PlayerYMovedArr[this.moveCount] - PlayerYMovedArr[this.moveCount + 1] == 1){
            this.enemyObj.style.top = "-25px";
            setTimeout(this.movingF, 280, this);
        }
        
        
        
    }
    
    movingF(enemy){
        mapBoxArr[PlayerYMovedArr[enemy.moveCount]][PlayerXMovedArr[enemy.moveCount]].removeChild(enemy.enemyObj);

        enemy.enemyObj.style.top = "0px";
        enemy.enemyObj.style.left = "0px";

        if(mapBoxArr[PlayerYMovedArr[++enemy.moveCount]][PlayerXMovedArr[enemy.moveCount]].innerHTML.indexOf("Enemy") != -1){
            mapBoxArr[PlayerYMovedArr[enemy.moveCount]][PlayerXMovedArr[enemy.moveCount]].style.overflow = "hidden";
        }
        if(mapBoxArr[PlayerYMovedArr[enemy.moveCount]][PlayerXMovedArr[enemy.moveCount]].innerHTML.indexOf("Player") != -1){
            gameover();
        }
        else{
            mapBoxArr[PlayerYMovedArr[enemy.moveCount]][PlayerXMovedArr[enemy.moveCount]].style.overflow = "visible";
        }


        mapBoxArr[PlayerYMovedArr[enemy.moveCount]][PlayerXMovedArr[enemy.moveCount]].appendChild(enemy.enemyObj);
        
        enemy.canMove = true;
    }
    
}


function provEnemy(){
    enemyArr.push(new Enemy());
}

//running game
function updateEnemy(){
    for(var i = 0; i < enemyArr.length; i++){
        enemyArr[i].moving();
    }
}