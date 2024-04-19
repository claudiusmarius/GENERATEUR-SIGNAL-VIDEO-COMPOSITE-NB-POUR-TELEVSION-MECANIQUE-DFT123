  // Petit generateur d'image fixe style mire TV en vue de la réalisation d'une télévision mécanique
  // C'est un signal vidéo composite donc commportant l'image + la synchro
  // L'image est constituée de barres N&B alternées dont le nombre est la variable "NombreAlternances"
  // https://www.youtube.com/c/ClaudeDufourmont
  
  #define BrocheSignalVideo D1
  #define BrocheSignalSynchro A0
  #define DureeSynch 200
  #define Periode 2500
  #define NombreAlternances 22
  void setup() 
  {
  pinMode(BrocheSignalVideo, OUTPUT);
  pinMode(BrocheSignalSynchro, OUTPUT);
  }

  void loop() 
  {
  analogWrite (BrocheSignalSynchro,0);
  delayMicroseconds (DureeSynch);
  analogWrite (BrocheSignalSynchro,450);
  
    for (int i = 0; i < NombreAlternances; i++) 
    {
    digitalWrite (BrocheSignalVideo,HIGH);
    delayMicroseconds((Periode -DureeSynch )/NombreAlternances/2);
    digitalWrite (BrocheSignalVideo,LOW);
    delayMicroseconds((Periode -DureeSynch )/NombreAlternances/2);
    }
  }
 
  
