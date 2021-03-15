/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pi
 */
public class Resultat {
    
    
     public long[] totaux = {0,0,0};
     public boolean[] erreurs = {false, false, false};
     public boolean fin = false;

    public Resultat() {
        
    }
    
    public Resultat(long[] totaux,boolean[] erreurs) {
        
        this.totaux = totaux;
        this.erreurs = erreurs;
        this.fin = false;
        
    }
     
    
    public long[] getTotaux() {
        return totaux;
    }

    public void setTotaux(long[] totaux) {
        this.totaux = totaux;
    }

    public boolean[] getErreurs() {
        return erreurs;
    }

    public void setErreurs(boolean[] erreurs) {
        this.erreurs = erreurs;
    }

    public boolean isFin() {
        return fin;
    }

    public void setFin(boolean fin) {
        this.fin = fin;
    }
    
    
     
     
    
}
