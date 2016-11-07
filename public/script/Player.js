window.addEventListener('keydown', Move);
window.addEventListener('on' + 'keydown', Move); //for fucking IE

canMove = true;

function Move(e){
    if(elapsedTime >= 220 && canMove){
        elapsedTime = 0;
        playerMove(e);
    }
    
}

function playerMove(e){
    //console.log('now pressed : ' + e.keyCode);
    if(e.keyCode == 38){ // up
        if(PlayerY > 0 && mapBoxArr[PlayerY - 1][PlayerX].className.indexOf("unavailableBlock") == -1){
            canMove = false;
            Player.src = "../resource/image/Player/Player_B_Up.png";
            Player.style.top = "-25px";
            moveOneBlock("up");
        }
    }
    else if(e.keyCode == 37){ // left
        if(PlayerX > 0 && mapBoxArr[PlayerY][PlayerX - 1].className.indexOf("unavailableBlock") == -1){
            canMove = false;
            Player.src = "../resource/image/Player/Player_B_Left.png";
            Player.style.left = "-25px";
            moveOneBlock("left");
        }
    }
    else if(e.keyCode == 40){ // down
        if(PlayerY < mapBoxArr.length - 1 && mapBoxArr[PlayerY + 1][PlayerX].className.indexOf("unavailableBlock") == -1){
            canMove = false;
            Player.src = "../resource/image/Player/Player_B_Down.png";
            Player.style.top = "25px";
            moveOneBlock("down");
        }
    }
    else if(e.keyCode == 39){ // right
        if(PlayerX < mapBoxArr[0].length - 1 && mapBoxArr[PlayerY][PlayerX + 1].className.indexOf("unavailableBlock") == -1){
            canMove = false;
            Player.src = "../resource/image/Player/Player_B_Right.png";
            Player.style.left = "25px";
            moveOneBlock("right");
        }
    }
}

function moveOneBlock(direction){
    setTimeout(function(){
        mapBoxArr[PlayerY][PlayerX].removeChild(Player);
        Player.style.left = "0px";
        Player.style.top = "0px";
    
        switch(direction){
            case "up":
                PlayerY--;
                PlayerImageArr.push("../resource/image/Enemy/Monster_B_Up.png");
                
                break;
            case "down":
                PlayerY++;
                PlayerImageArr.push("../resource/image/Enemy/Monster_B_Down.png");
                
                break;
            case "left":
                PlayerX--;
                PlayerImageArr.push("../resource/image/Enemy/Monster_B_Left.png");
                
                break;
            case "right":
                PlayerX++;
                PlayerImageArr.push("../resource/image/Enemy/Monster_B_Right.png");
                
                break;
            default:
                console.log("Error detected at direction : function moveOneBlock at Player.js");
                return;
        }

        PlayerY = (PlayerY < 0)? 0 : (PlayerY >= mapBoxArr.length)? mapBoxArr.length - 1 : PlayerY;
        PlayerX = (PlayerX < 0)? 0 : (PlayerX >= mapBoxArr[0].length)? mapBoxArr[0].length - 1 : PlayerX;

        if(mapBoxArr[PlayerY][PlayerX].innerHTML.indexOf("Enemy") != -1){
            gameover();
        }

        mapBoxArr[PlayerY][PlayerX].appendChild(Player);

        PlayerXMovedArr.push(PlayerX);
        PlayerYMovedArr.push(PlayerY);
        
        canMove = true;
    }, 210);
    
}