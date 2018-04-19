#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME MSDO


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }


  typedef vector<int> VE;
  typedef vector<bool> VB;
  typedef vector<VB> VVB;
  
 
  bool cela_tipo1(Pos p) {
      Cell x = cell(p);
      bool ret = (x.type == Empty) and (x.id == -1) and (not x.haunted);
      if (ret) {
          for (int i = 0; i < 8; ++i) {
              x = cell(p+Dir(i));
              if (x.haunted) return false; 
              if (i%2 == 0) {
                  x = cell(p+Dir(i)+Dir(i));
                    if (x.haunted) return false;   
              }
          }          
      }
      return ret;
  }
  
  bool direccio_dins(vector<Dir> &VC, Dir D) {
      for (int i = 0; i < (int)VC.size(); ++i) {
          if (VC[i] == D) return true;          
      }
      return false;
  }
  
  //####################### FARMER #######################  
  bool cela_correcta(Pos p) {
      Cell x = cell(p);
      return (x.type == Empty) and (x.owner != 0) and (x.id == -1) and (not x.haunted);
  }    
  //retorna la direcció que ha d'agafar si esta a "a" per anar fins a "b"
  Dir direccioF(Pos a, Pos b) {
      
        vector<Dir> VC;
        for (int i = 0; i <= 6; i+=2) {
            if (cela_tipo1(a+Dir(i))) VC.push_back(Dir(i));
        }
        
        //busquem la direcció de dins de VC millor per arribar a "b" 
        if (a.i < b.i and a.j == b.j) {
            if (direccio_dins(VC,Dir(0))) return Dir(0);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i > b.i and a.j == b.j) {
            if (direccio_dins(VC,Dir(4))) return Dir(4);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i == b.i and a.j < b.j) {
            if (direccio_dins(VC,Dir(2))) return Dir(2);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i == b.i and a.j > b.j) {
            if (direccio_dins(VC,Dir(6))) return Dir(6);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i > b.i and a.j < b.j) {
            if (direccio_dins(VC,Dir(4))) return Dir(4);
            else if (direccio_dins(VC,Dir(2))) return Dir(2);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i < b.i and a.j > b.j) {
            if (direccio_dins(VC,Dir(0))) return Dir(0);
            else if (direccio_dins(VC,Dir(6))) return Dir(6);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i < b.i and a.j < b.j) {
            if (direccio_dins(VC,Dir(0))) return Dir(0);
            else if (direccio_dins(VC,Dir(2))) return Dir(2);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else {
            if (direccio_dins(VC,Dir(4))) return Dir(4);
            else if (direccio_dins(VC,Dir(6))) return Dir(6);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        } 
        
        return Dir(8);
  }
  
  Dir direccio_farmer(int id) {
      // buscar la direcció del farmer cap a la cel·la més pròxima
      
      VVB tauler(37,VB(37,false));
      queue<Pos> no_visitades;      
      no_visitades.push(unit(id).pos);      
      bool primer = true;
      while (not no_visitades.empty()) {
          Pos P = no_visitades.front();
          no_visitades.pop();
          for (int i = 0; i <= 6; i += 2) {              
              if (cela_correcta(P+Dir(i))) {
                  if (primer) return Dir(i);                  
                  return direccioF(unit(id).pos, P+Dir(i));    
                  
              }
              else if (cell(P+Dir(i)).type == Empty and not tauler[(P+Dir(i)).i][(P+Dir(i)).j]) {
                  //suposem que si una cela está ocupada, a la seguent ronda no ho estará
                  no_visitades.push(P+Dir(i));  
                  tauler[(P+Dir(i)).i][(P+Dir(i)).j] = true;
              }
          }          
          primer = false;          
      }      
      return Dir(8);
  }
  //####################### FARMER #######################
  
  //------------------------------------------------------
  
  //####################### KNIGHT #######################
  int distancia(Pos A, Pos B) {
      return (sqrt((pow((A.i-B.i),2))+(pow((A.j-B.j),2))));
  }
  
  bool cela_atacK(Pos P) {   
      Cell x = cell(P);
      if ((x.type == Empty) and (x.id != -1)) {
          if (unit(x.id).type == Knight and unit(x.id).player != 0) return true;          
      }
      return false;
  }  
  bool cela_atacF(Pos P) {   
      Cell x = cell(P);
      if ((x.type == Empty) and (x.id != -1)) {
          if (unit(x.id).type == Farmer and unit(x.id).player != 0) return true;          
      }
      return false;
  } 
    
  //retorna la direcció que ha d'agafar si esta a "a" per anar fins a "b"
  Dir direccioK(Pos a, Pos b) {  
      
        vector<Dir> VC;
        for (int i = 0; i < 8; ++i) {
            if (cela_tipo1(a+Dir(i))) VC.push_back(Dir(i));
        }
        
        //busquem la direcció de dins de VC millor per arribar a "b" 
        if (a.i < b.i and a.j == b.j) {
            if (direccio_dins(VC,Dir(0))) return Dir(0);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i > b.i and a.j == b.j) {
            if (direccio_dins(VC,Dir(4))) return Dir(4);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i == b.i and a.j < b.j) {
            if (direccio_dins(VC,Dir(2))) return Dir(2);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i == b.i and a.j > b.j) {
            if (direccio_dins(VC,Dir(6))) return Dir(6);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i > b.i and a.j < b.j) {
            if (direccio_dins(VC,Dir(3))) return Dir(3);
            else if (direccio_dins(VC,Dir(4))) return Dir(4);
            else if (direccio_dins(VC,Dir(2))) return Dir(2);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i < b.i and a.j > b.j) {
            if (direccio_dins(VC,Dir(7))) return Dir(7);
            else if (direccio_dins(VC,Dir(0))) return Dir(0);
            else if (direccio_dins(VC,Dir(6))) return Dir(6);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i < b.i and a.j < b.j) {
            if (direccio_dins(VC,Dir(1))) return Dir(1);
            else if (direccio_dins(VC,Dir(0))) return Dir(0);
            else if (direccio_dins(VC,Dir(2))) return Dir(2);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else {
            if (direccio_dins(VC,Dir(5))) return Dir(5);
            else if (direccio_dins(VC,Dir(4))) return Dir(4);
            else if (direccio_dins(VC,Dir(6))) return Dir(6);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        } 
        
        return Dir(0);
   
  }
    
  Dir direccio_knight(int id) {
      // buscar la direcció del knight cap a l'enemic més a prop
      int distK = 0;
      int distF = 0;
      
      //buscar knight més pròxim
      VVB tauler(37,VB(37,false));
      queue<Pos> no_visitades;         
      no_visitades.push(unit(id).pos);  
      Dir ret = Dir(8);
      bool primer = true;
      bool trobat = false;           
      while (not no_visitades.empty() and not trobat) {
          Pos P = no_visitades.front();
          no_visitades.pop();
          for (int i = 0; i < 8; ++i) {              
              if (cela_atacK(P+Dir(i))) {
                  if (primer) return Dir(i);                  
                  ret = direccioK(unit(id).pos, P+Dir(i));
                    trobat = true;
                    distK = distancia(unit(id).pos, P+Dir(i));
              }
              else if (cell(P+Dir(i)).type == Empty and not tauler[(P+Dir(i)).i][(P+Dir(i)).j]) {
                  no_visitades.push(P+Dir(i));  
                  tauler[(P+Dir(i)).i][(P+Dir(i)).j] = true;
              }
          }          
          primer = false;          
       }   
       //buscar farmer més pròxim
      VVB tauler2(37,VB(37,false));
      queue<Pos> no_visitades2;         
      no_visitades2.push(unit(id).pos);  
      Dir ret2 = Dir(8);
      bool primer2 = true;
      bool trobat2 = false;     
      //buscar knight més pròxim
      while (not no_visitades2.empty() and not trobat2) {
          Pos P = no_visitades2.front();
          no_visitades2.pop();
          for (int i = 0; i < 8; ++i) {              
              if (cela_atacF(P+Dir(i))) {
                  if (primer2) return Dir(i);                  
                    ret2 = direccioK(unit(id).pos, P+Dir(i));
                    trobat2 = true;
                    distF = distancia(unit(id).pos, P+Dir(i));
              }
              else if (cell(P+Dir(i)).type == Empty and not tauler2[(P+Dir(i)).i][(P+Dir(i)).j]) {
                  no_visitades2.push(P+Dir(i));  
                  tauler2[(P+Dir(i)).i][(P+Dir(i)).j] = true;
              }
          }          
          primer2 = false;          
       } 
       if (distK - distF <= 2) return ret;
       else return ret2;
      
  }  
  //####################### KNIGHT #######################
  
  //------------------------------------------------------
  
  //####################### WITCH #######################

  bool cela_correcta2(Pos P) {
      Cell x = cell(P);
      return ((x.type == Empty) and (x.id == -1));
              
  }
  
  bool cela_atac(Pos P) {   
      Cell x = cell(P);
      int n_enemics = 0;
      if ((x.type == Empty) and (x.id != -1)) {
          if (unit(x.id).type != Witch and unit(x.id).player != 0) ++n_enemics;          
      }
      for (int i = 0; i < 8; ++i) {
          x = cell(P+Dir(i));
          if ((x.type == Empty) and (x.id != -1)) {
            if (unit(x.id).type != Witch and unit(x.id).player != 0) ++n_enemics;          
          }
      }
      if (n_enemics >= 2) return true;
      return false;
  } 
  
  Dir direccioW(Pos a, Pos b) {
      vector<Dir> VC;
        for (int i = 0; i < 8; ++i) {
            if (cela_correcta2(a+Dir(i))) VC.push_back(Dir(i));
        }
      //busquem la direcció de dins de VC millor per arribar a "b" 
        if (a.i < b.i and a.j == b.j) {
            if (direccio_dins(VC,Dir(0))) return Dir(0);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i > b.i and a.j == b.j) {
            if (direccio_dins(VC,Dir(4))) return Dir(4);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i == b.i and a.j < b.j) {
            if (direccio_dins(VC,Dir(2))) return Dir(2);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i == b.i and a.j > b.j) {
            if (direccio_dins(VC,Dir(6))) return Dir(6);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i > b.i and a.j < b.j) {
            if (direccio_dins(VC,Dir(4))) return Dir(4);
            else if (direccio_dins(VC,Dir(2))) return Dir(2);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i < b.i and a.j > b.j) {
            if (direccio_dins(VC,Dir(0))) return Dir(0);
            else if (direccio_dins(VC,Dir(6))) return Dir(6);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else if (a.i < b.i and a.j < b.j) {
            if (direccio_dins(VC,Dir(0))) return Dir(0);
            else if (direccio_dins(VC,Dir(2))) return Dir(2);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        }
        else {
            if (direccio_dins(VC,Dir(4))) return Dir(4);
            else if (direccio_dins(VC,Dir(6))) return Dir(6);
            else if (VC.size() > 0) return VC[random(0,VC.size()-1)];
        } 
        
        return Dir(8);
  }
  
  Dir direccio_witch(int id) {
      //buscar la direcció de la bruixa cap a l'enemic més pròxim
      VVB tauler(37,VB(37,false));
      queue<Pos> no_visitades;      
      no_visitades.push(unit(id).pos);      
      
      while (not no_visitades.empty()) {
          Pos P = no_visitades.front();
          no_visitades.pop();
          for (int i = 0; i <= 6; i+=2) {              
              if (cela_atac(P+Dir(i))) {                                   
                  return direccioW(unit(id).pos, P+Dir(i));                  
              }
              else if (cell(P+Dir(i)).type == Empty and not tauler[(P+Dir(i)).i][(P+Dir(i)).j]) {
                  no_visitades.push(P+Dir(i));  
                  tauler[(P+Dir(i)).i][(P+Dir(i)).j] = true;
              }
          }     
      }     
      return Dir(8);
  }
  
  //####################### WITCH #######################

  
  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
    
    //farmers
    VE f = farmers(0);
    for (int id : f) {
        command(id,direccio_farmer(id));    
    }
    
    //knights
    VE k = knights(0);
    for (int id : k) {
        command(id,direccio_knight(id));     
    }
    
    //witches
    VE w = witches(0);
    bool primera = true;
    for (int id : w) {
       command(id,direccio_witch(id));             
    }

  }

};

// ./Game MSDO Demo Demo Demo -s 30 -i default.cnf -o default.res
// ./Game MSDO Dummy Dummy Dummy -s 30 -i default.cnf -o default.res
/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
