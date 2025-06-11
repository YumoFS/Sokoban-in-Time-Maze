#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stdexcept>
#include<windows.h>
#include<cstdio>
#define keyPressed(thisKey) ((GetAsyncKeyState(thisKey) & 0x8000)? 1:0)

using namespace std;

const int PlayerSign = '1', BoxSign = '2';//Can be moved
const int EmptySign = '0', WallSign = '3', 
        UntrackingPt = '4', DestinationPt = '5',
        TeleportPt = '6';//Can't be moved

bool isArrived = false;

class Sokoban{
public:
    Sokoban(vector<string> map): emptyMap(map), plMove(vector(1, vector<int>(2))), objectsLoc(vector(1, vector<int>(2))){
        //Initialize of vector "objects"
        //obj[0] for player, other num for boxes
        //plMove[t][0]=j for pl acting j move, 1234 for Up, Down, Left and Right,
        //  [t][1] for pl pushing box1, at step t.
        for(int i=0; i<map.size(); i++) for(int j=0; j<map[i].size(); j++){
            if(map[i][j]==PlayerSign){
                emptyMap[i][j] = EmptySign;
                objectsLoc[0][0] = i; objectsLoc[0][1] = j;
            }else if(map[i][j] == BoxSign){
                emptyMap[i][j] = EmptySign;
                vector<int> boxLoc = {i, j};
                objectsLoc.push_back(boxLoc);
            }else if(map[i][j] == TeleportPt){
                teleportX.push_back(i);
                teleportY.push_back(j);
            }
        }
    }

    //Show map
    void showMap(){
        vector<string> gameMap = emptyMap;
        gameMap[objectsLoc[0][0]][objectsLoc[0][1]] = PlayerSign;
        for(int i=1; i<objectsLoc.size(); i++) 
            gameMap[objectsLoc[i][0]][objectsLoc[i][1]] = BoxSign;
        for(int i=0; i<gameMap.size(); i++){
            for(int j=0; j<gameMap[i].size(); j++){
                switch(gameMap[i][j]){
                    case PlayerSign:    cout<<"@"; break;
                    case BoxSign:       cout<<"*"; break;
                    case WallSign:      cout<<"#"; break;
                    case UntrackingPt:  cout<<"S"; break;
                    case DestinationPt: cout<<"E"; break;
                    case EmptySign:     cout<<" "; break;
                    case TeleportPt:    cout<<"T"; break;
                }
            }
            cout<<endl;
        }
    }

    bool movePl(int dir){
        int xpl = objectsLoc[0][0], ypl = objectsLoc[0][1];
        vector<string> gameMap = emptyMap;
        gameMap[xpl][ypl] = PlayerSign;
        for(int i=0; i<objectsLoc.size(); i++) 
            gameMap[objectsLoc[i][0]][objectsLoc[i][1]] = BoxSign;
        
        //Update temporary loc
        switch(dir){
            case 1: xpl--; break; //up
            case 2: xpl++; break; //down
            case 3: ypl--; break; //left
            case 4: ypl++; break; //right
            default: return false;
        }

        //Check if legal pl movement
        if(xpl<0 || xpl>=gameMap.size() || ypl<0 || ypl>=gameMap[xpl].size())
            return false;
        
        char tar = gameMap[xpl][ypl];

        if(tar==WallSign) return false; //Hit the wall
        if(tar==EmptySign || tar==UntrackingPt || tar==DestinationPt || tar==TeleportPt){
            //Legal move to Space, UntrackingPt, Destination or TeleportPt
            //Record pl loc in objLoc and all movements in objMove
            objectsLoc[0][0] = xpl; objectsLoc[0][1] = ypl;
            plMove.push_back({dir, 0});  
            if(tar==DestinationPt) isArrived = true;
            return true;
        }
        
        if(tar==BoxSign){
            //Pushing the box
            int xbox = xpl, ybox = ypl;
            int ibox = 1;
            for(ibox; ibox<objectsLoc.size(); ibox++) if(objectsLoc[ibox][0]==xbox && objectsLoc[ibox][1]==ybox) break;
            switch(dir){
                case 1: xbox--; break; //up
                case 2: xbox++; break; //down
                case 3: ybox--; break; //left
                case 4: ybox++; break; //right
                default: return false;
            }

            //Check if legal box movement
            if(xbox<0 || xbox>=gameMap.size() || ybox<0 || ybox>=gameMap[xbox].size())
                return false;
            
            char boxTar = gameMap[xbox][ybox];
            if(boxTar==EmptySign || boxTar==UntrackingPt){
                //Legal box move to Space or UntrackingPt
                //Record pl&box loc in objLoc and all movements in objMove
                objectsLoc[0][0] = xpl; objectsLoc[0][1] = ypl;
                objectsLoc[ibox][0] = xbox; objectsLoc[ibox][1] = ybox;
                plMove.push_back({dir, ibox});    
                return true;
            }
        }
        return false;
    }

    bool teleportPl(){
        int xpl = objectsLoc[0][0], ypl = objectsLoc[0][1];
        if (emptyMap[xpl][ypl] == TeleportPt){
            if (xpl == teleportX[0] && ypl == teleportY[0]){
                objectsLoc[0][0] = teleportX[1]; objectsLoc[0][1] = teleportY[1];
                plMove.push_back({5, 0});
            }else {
                objectsLoc[0][0] = teleportX[0]; objectsLoc[0][1] = teleportY[0];
                plMove.push_back({5, 0});
            }
            return true;
        }else return false;
    }

    bool trackBack(){
        // int objectsSize = const_cast<int> (objectsLoc.size());
        // int notTracking[objectsLoc.size()] = {0};
        int* notTracking = new int[objectsLoc.size()]();
        for(int i=0; i<objectsLoc.size(); i++){
            if(emptyMap[objectsLoc[i][0]][objectsLoc[i][1]]==UntrackingPt){
                notTracking[i] = 1;
            }       
        }
        while(plMove.size()>1){
            int dir = plMove.back()[0],ibox = plMove.back()[1];
            if(notTracking[0]==0){ //pl is not fixed
                int xpl = objectsLoc[0][0], ypl = objectsLoc[0][1];
                switch(dir){
                    case 1: xpl++; break; //up --> down when tracking
                    case 2: xpl--; break; //down --> up when tracking
                    case 3: ypl++; break; //left --> right when tracking
                    case 4: ypl--; break; //right --> left when tracking
                    case 5: if (xpl == teleportX[0]) {xpl=teleportX[1];ypl=teleportY[1];} else {xpl=teleportX[0];ypl=teleportY[0];} break;
                    default: return false;
                }
                objectsLoc[0][0] = xpl; objectsLoc[0][1] = ypl;
            }
            if(ibox!=0 && notTracking[ibox]==0){ //a box has moved
                int xbox = objectsLoc[ibox][0], ybox = objectsLoc[ibox][1];
                switch(dir){
                    case 1: xbox++; break; //up --> down when tracking
                    case 2: xbox--; break; //down --> up when tracking
                    case 3: ybox++; break; //left --> right when tracking
                    case 4: ybox--; break; //right --> left when tracking
                    default: return false;
                }
                objectsLoc[ibox][0] = xbox; objectsLoc[ibox][1] = ybox;
            }
            plMove.pop_back();
            system("cls");
            showMap();
            Sleep(100);      
        }
        return true;
    }

private:
    vector<string> emptyMap;
    vector<vector<int>> objectsLoc, plMove;
    vector<int> teleportX, teleportY;
};


vector<string> getMap(int numberMap){
    string fileName = "map"+to_string(numberMap)+".txt";

    //Open File
    ifstream file(fileName);

    //Check if opened successfully
    if(!file.is_open()) throw runtime_error("Can not open file: "+fileName);

    string line;
    vector<string> map;

    //Read by line and push into vector "map"
    while(getline(file, line)) map.push_back(line);

    file.close();
    return map;
}

int main(){
    int numMap = 0;
    bool restart = false, endGame = false;
    while(!endGame){
        //Initializer
        isArrived = false;
        endGame = false;
        system("cls");

        //Get map code
        if(!restart){
            cout<<"Operations:"<<endl
                <<"W: Up"<<endl
                <<"S: Down"<<endl
                <<"A: Left"<<endl
                <<"D: Right"<<endl
                <<"O: Retry"<<endl
                <<"Space: Teleport"<<endl
                <<"P: Another Map"<<endl<<endl
                <<"Please choose a map (1~6): "<<endl;
            cin>>numMap;
        }else restart = false;
        vector<string> map = getMap(numMap);
        system("cls");

        Sokoban game(map);
        game.showMap();

        while(!isArrived){
            if(keyPressed(87)){ //Ww pressed
                game.movePl(1);
                system("cls");
                game.showMap();
                Sleep(200);
            }else if(keyPressed(83)){ //Ss pressed
                game.movePl(2);
                system("cls");
                game.showMap();
                Sleep(200);
            }else if(keyPressed(65)){ //Aa pressed
                game.movePl(3);
                system("cls");
                game.showMap();
                Sleep(200);
            }else if(keyPressed(68)){ //Dd pressed
                game.movePl(4);
                system("cls");
                game.showMap();
                Sleep(200);
            }else if(keyPressed(82)){ //Rr pressed
                game.trackBack();
                Sleep(200);
            }else if(keyPressed(79)){ //Oo pressed
                restart = true;
                break;
            }else if (keyPressed(32)){//Space pressed
                game.teleportPl();
                system("cls");
                game.showMap();
                Sleep(200);
            }else if(keyPressed(80)) break; //Pp pressed
        }
        if(isArrived){
            cout<<"You Win!!"<<endl;
            cout<<"Press Esc to exit, P to restart.";
            while(1){
                if(keyPressed(80)){ //Esc pressed
                    cout<<"Thanks for playing."<<endl;
                    break;
                }else if(keyPressed(27)){ //Pp pressed
                    endGame = true;
                    break;
                }
            }      
        }
    }
    return 0;
}