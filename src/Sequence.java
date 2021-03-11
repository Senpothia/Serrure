

import com.pi4j.io.gpio.GpioController;
import com.pi4j.io.gpio.GpioFactory;
import com.pi4j.io.gpio.GpioPinDigitalInput;
import com.pi4j.io.gpio.GpioPinDigitalOutput;
import com.pi4j.io.gpio.PinPullResistance;
import com.pi4j.io.gpio.PinState;
import com.pi4j.io.gpio.RaspiPin;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pi
 */
public class Sequence implements Runnable{
    
    
     // GPIO  -- Version Raspberry
    
     final GpioController gpio = GpioFactory.getInstance();
     final GpioPinDigitalOutput relais1 = gpio.provisionDigitalOutputPin(RaspiPin.GPIO_25, "REL1", PinState.LOW);
     final GpioPinDigitalOutput relais2 = gpio.provisionDigitalOutputPin(RaspiPin.GPIO_28, "REL2", PinState.LOW);
     final GpioPinDigitalOutput relais3 = gpio.provisionDigitalOutputPin(RaspiPin.GPIO_29, "REL3", PinState.LOW);
      
     final GpioPinDigitalInput sensor1 = gpio.provisionDigitalInputPin(RaspiPin.GPIO_02, PinPullResistance.PULL_UP);
     final GpioPinDigitalInput sensor2 = gpio.provisionDigitalInputPin(RaspiPin.GPIO_03, PinPullResistance.PULL_UP);
     final GpioPinDigitalInput sensor3 = gpio.provisionDigitalInputPin(RaspiPin.GPIO_04, PinPullResistance.PULL_UP);
     
     final GpioPinDigitalInput contact1 = gpio.provisionDigitalInputPin(RaspiPin.GPIO_05, PinPullResistance.PULL_UP);
     final GpioPinDigitalInput contact2 = gpio.provisionDigitalInputPin(RaspiPin.GPIO_06, PinPullResistance.PULL_UP);
     final GpioPinDigitalInput contact3 = gpio.provisionDigitalInputPin(RaspiPin.GPIO_07, PinPullResistance.PULL_UP);
     
     private boolean stateSensor1;
     private boolean stateSensor2;
     private boolean stateSensor3;
     
     private boolean stateContact1;
     private boolean stateContact2;
     private boolean stateContact3;
     
     private GpioPinDigitalOutput[] relais = {relais1, relais2, relais3};
     private GpioPinDigitalInput[] sensors = {sensor1, sensor2, sensor3};
     private GpioPinDigitalInput[] contacts = {contact1, contact2, contact3};

    
    public void run() {
       
       
       
       System.out.println("***** Nouvelle sequence  *****");
       for(int i=0; i<3; i++){
       
       if (Interface.actifs[i]){
       
       // activer relais
       System.out.println("Activation relais: " + i);
       relais[i].high();
       // delai anti-rebond
           try {
               Thread.sleep(300);
           } catch (InterruptedException ex) {
               Logger.getLogger(Sequence.class.getName()).log(Level.SEVERE, null, ex);
           }
       
       // désactiver relais
       relais[i].low();
       // lecture sensor
       System.out.println("Lecture sensor: " + i);
       boolean sensor = sensors[i].isHigh();
       // lecture contact
       System.out.println("Lecture contact: " + i);
       boolean contact = contacts[i].isHigh();
       // incrémentation compteur - invalidation echantillon
       if (!sensor && contact){
       
           Interface.totaux[i]++;
           System.out.println("Total echantillon:" + i + " " + Interface.totaux[i]);
       
       }else{
       
       
           Interface.actifs[i] = false;
           Interface.erreurs[i] = true;
       }
       
           try {
               Thread.sleep(5000);
           } catch (InterruptedException ex) {
               Logger.getLogger(Sequence.class.getName()).log(Level.SEVERE, null, ex);
           }
      
       }
       
       }
       
         System.out.println("***** Fin de sequence  *****");
       
       }
      
      
 
    }

   
   
    
    
    

