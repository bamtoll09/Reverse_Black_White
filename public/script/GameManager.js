window.addEventListener('load', __init__);
window.addEventListener('on' + 'load', __init__); // for IE

function __init__(){
    elapsedTime = 0;
    createMap(30, 20, 25, document.getElementsByTagName("body")[0]);
    Player = document.createElement('img');
    Player.id = "Player";
    Player.src = "../resource/image/Player/Player_B_Down.png";
    PlayerX = 1;
    PlayerY = 3;
    PlayerXMovedArr = new Array();
    PlayerYMovedArr = new Array();
    PlayerImageArr = new Array();
    mapBoxArr[PlayerY][PlayerX].appendChild(Player);
    enemyArr = new Array();
    PlayerXMovedArr.push(PlayerX);
    PlayerYMovedArr.push(PlayerY);
    setTimeout(startEnemyUpdate, 10000);
    PlayerDelay = setInterval(function (){
        elapsedTime += 10;
    }, 10);
}

function startEnemyUpdate(){
    enemyCreator = setInterval(provEnemy, 3000);
    enemyUpdater = setInterval(updateEnemy, 300);
}

function createMap(cols, rows, boxLen, parentBox){
    var mapBox = document.createElement('div');
    
    initArray(cols, rows);
    
    mapBox.className = "map";
    mapBox.id = "mapBox";
    mapBox.style.width = (boxLen * cols) + "px";
    mapBox.style.height = (boxLen * rows) + "px";
    
    for(var i = 0; i < rows; i++){
        for(var j = 0; j < cols; j++){
            if(true){ // for repetitive inserting boxes
                var mapPart = document.createElement('div');
                
                //mapPart.className = "map mapPart";
                mapPart.style.width = boxLen + "px";
                mapPart.style.height = boxLen + "px";
                
                //if(Math.round(Math.random() * 2) == 0) mapPart.className = "map mapPart unavailableBlock";
                //else mapPart.className = "map mapPart availableBlock";
                
                //mapPart.className = "map mapPart availableBlock";
                
                if(i == 0){
                    switch(j){
                        case 0:
                        case 2:
                        case 6:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 1){
                    switch(j){
                        case 0:
                        case 4:
                        case 6:
                        case 8:
                        case 10:
                        case 11:
                        case 12:
                        case 13:
                        case 15:
                        case 17:
                        case 18:
                        case 19:
                        case 20:
                        case 21:
                        case 22:
                        case 24:
                        case 26:
                        case 27:
                        case 28:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 2){
                    switch(j){
                        case 0:
                        case 1:
                        case 2:
                        case 4:
                        case 6:
                        case 8:
                        case 13:
                        case 15:
                        case 24:
                        case 26:
                        case 27:
                        case 28:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 3){
                    switch(j){
                        case 0:
                        case 2:
                        case 4:
                        case 6:
                        case 8:
                        case 9:
                        case 10:
                        case 11:
                        case 13:
                        case 15:
                        case 16:
                        case 17:
                        case 18:
                        case 20:
                        case 22:
                        case 24:
                        case 26:
                        case 27:
                        case 28:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 4){
                    switch(j){
                        case 0:
                        case 4:
                        case 6:
                        case 11:
                        case 13:
                        case 18:
                        case 20:
                        case 21:
                        case 24:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 5){
                    switch(j){
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                        case 6:
                        case 8:
                        case 9:
                        case 11:
                        case 13:
                        case 14:
                        case 15:
                        case 16:
                        case 18:
                        case 20:
                        case 22:
                        case 24:
                        case 26:
                        case 28:
                        case 29:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 6){
                    switch(j){
                        case 6:
                        case 11:
                        case 18:
                        case 20:
                        case 22:
                        case 24:
                        case 25:
                        case 26:
                        case 27:
                        case 29:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 7){
                    switch(j){
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                        case 6:
                        case 8:
                        case 13:
                        case 16:
                        case 18:
                        case 25:
                        case 26:
                        case 29:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 8){
                    switch(j){
                        case 0:
                        case 6:
                        case 8:
                        case 10:
                        case 11:
                        case 13:
                        case 16:
                        case 18:
                        case 20:
                        case 21:
                        case 22:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 9){
                    switch(j){
                        case 0:
                        case 2:
                        case 4:
                        case 6:
                        case 8:
                        case 10:
                        case 11:
                        case 13:
                        case 16:
                        case 20:
                        case 22:
                        case 24:
                        case 26:
                        case 27:
                        case 28:
                        case 29:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 10){
                    switch(j){
                        case 0:
                        case 4:
                        case 6:
                        case 8:
                        case 10:
                        case 11:
                        case 13:
                        case 16:
                        case 18:
                        case 20:
                        case 22:
                        case 24:
                        case 26:
                        case 28:
                        case 29:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 11){
                    switch(j){
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                        case 6:
                        case 8:
                        case 10:
                        case 11:
                        case 13:
                        case 16:
                        case 18:
                        case 20:
                        case 22:
                        case 24:
                        case 25:
                        case 26:
                        case 28:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 12){
                    switch(j){
                        case 6:
                        case 8:
                        case 10:
                        case 11:
                        case 13:
                        case 14:
                        case 15:
                        case 16:
                        case 18:
                        case 20:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 13){
                    switch(j){
                        case 1:
                        case 3:
                        case 4:
                        case 8:
                        case 21:
                        case 23:
                        case 24:
                        case 26:
                        case 27:
                        case 28:
                        case 29:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 14){
                    switch(j){
                        case 1:
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                        case 8:
                        case 10:
                        case 11:
                        case 12:
                        case 13:
                        case 14:
                        case 15:
                        case 16:
                        case 19:
                        case 21:
                        case 23:
                        case 24:
                        case 29:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 15){
                    switch(j){
                        case 1:
                        case 16:
                        case 19:
                        case 21:
                        case 23:
                        case 24:
                        case 26:
                        case 27:
                        case 28:
                        case 29:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 16){
                    switch(j){
                        case 1:
                        case 3:
                        case 5:
                        case 7:
                        case 10:
                        case 11:
                        case 12:
                        case 13:
                        case 14:
                        case 16:
                        case 19:
                        case 21:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 17){
                    switch(j){
                        case 1:
                        case 3:
                        case 5:
                        case 6:
                        case 7:
                        case 8:
                        case 10:
                        case 11:
                        case 12:
                        case 13:
                        case 14:
                        case 16:
                        case 17:
                        case 18:
                        case 19:
                        case 21:
                        case 22:
                        case 23:
                        case 25:
                        case 26:
                        case 27:
                        case 29:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 18){
                    switch(j){
                        case 1:
                        case 5:
                        case 7:
                        case 23:
                        case 27:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                else if(i == 19){
                    switch(j){
                        case 3:
                        case 4:
                        case 5:
                        case 9:
                        case 10:
                        case 11:
                        case 12:
                        case 13:
                        case 14:
                        case 15:
                        case 16:
                        case 17:
                        case 18:
                        case 19:
                        case 20:
                        case 21:
                        case 25:
                        case 26:
                        case 27:
                        case 28:
                        case 29:
                            mapPart.className = "map mapPart unavailableBlock";
                            break;
                        default:
                            mapPart.className = "map mapPart availableBlock";
                    }
                }
                mapBoxArr[i][j] = mapPart;
                
                mapBox.appendChild(mapPart);
            }
        }
    }
    
    parentBox.appendChild(mapBox);
    mapBox.style.marginLeft = "calc(50% - " + (mapBox.clientWidth / 2) + "px)";
    mapBox.style.opacity = "1";
    BeforeTimer = setInterval(BeforeGameSet, 1000);
    //console.log(mapBox.childNodes.length);
}

function initArray(cols, rows){
    mapBoxArr = new Array(rows);
    
    for(var i = 0; i < rows; i++){
        mapBoxArr[i] = new Array(cols);
    }
}

function gameover(){
    clearInterval(enemyUpdater);
    clearInterval(enemyCreator);
    clearInterval(PlayerDelay);
    clearInterval(AfterTimer);
    
    console.log("game over");
}