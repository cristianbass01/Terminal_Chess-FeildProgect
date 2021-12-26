void Scacchiera::stampa() {
    for(int i = 0; i < RIGHE; i++) {
        std::cout<<RIGHE-i<<' ';
        for(int j = 0; j < COLONNE; j++) {
            if(scacchiera[i][j]==nullptr)
                std::cout<<" ";
            else 
                std::cout<<scacchiera[i][j].figura;
        }
        std::cout<<std::endl;
    }
    std::cout<<"  "<<"ABCDEFGH"<<std::endl;
            
}