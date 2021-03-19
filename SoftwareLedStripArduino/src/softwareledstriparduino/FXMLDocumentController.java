/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package softwareledstriparduino;

import com.fazecast.jSerialComm.SerialPort;
import java.io.PrintWriter;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;

/**
 *
 * @author rhyan
 */
public class FXMLDocumentController implements Initializable {

    @FXML
    private ComboBox cbPortas;

    @FXML
    private Button btnConectar;

    @FXML
    private Button btnReset;

    @FXML
    private Button btnR;
    @FXML
    private Button btnG;
    @FXML
    private Button btnB;
    @FXML
    private Button btnW;

    private SerialPort porta;
    private char RainbowCycle = '0';
    private char RGBLoop = '0';
    private char FadeInOut = '0';
    private char RunningLights = '0';
    private char ColorWipe = '0';

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        carregarPortas();
    }

    private void carregarPortas() {
        SerialPort[] portNames = SerialPort.getCommPorts();
        for (SerialPort portName : portNames) {
            cbPortas.getItems().add(portName.getSystemPortName());
        }
    }

    @FXML
    private void conectar() {
        if (btnConectar.getText().equals("Conectar")) {
            porta = SerialPort.getCommPort(cbPortas.getSelectionModel().getSelectedItem().toString());

            if (porta.openPort()) {
                btnConectar.setText("Desconectar");
                cbPortas.setDisable(true);
            }

        } else {
            porta.closePort();
            cbPortas.setDisable(false);
            btnConectar.setText("Conectar");
        }

    }

    /**
     * EFEITOS
     *
     */
    @FXML
    private void reset() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (btnReset.getText().equals("Reset")) {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    @FXML
    private void ligarRainbowCycle() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (RainbowCycle == '0') {
            outputFITA.print('1');
            outputFITA.flush();
            RainbowCycle = '1';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            RainbowCycle = '0';
        }
    }

    @FXML
    private void ligarRGBLoop() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (RGBLoop == '0') {
            outputFITA.print('2');
            outputFITA.flush();
            RGBLoop = '2';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            RGBLoop = '0';
        }
    }

    @FXML
    private void ligarFadeInOut() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (FadeInOut == '0') {
            outputFITA.print('3');
            outputFITA.flush();
            FadeInOut = '3';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            FadeInOut = '0';
        }
    }

    /*MERDAS*/
//    RunningLights
    @FXML
    private void RunningLightsRED() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());
        if (RunningLights == '0') {
            outputFITA.print('4');
            outputFITA.flush();
            ColorWipe = '4';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            RunningLights = '0';
        }
    }
//    RunningLightsGREEN
//    RunningLightsBLUE

    //COLOR WIPE
    @FXML
    private void ColorWipeRED() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (ColorWipe == '0') {
            outputFITA.print('7');
            outputFITA.flush();
            ColorWipe = '7';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            ColorWipe = '0';
        }

        if (btnR.getText().equals("Red")) {
            outputFITA.print('g');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }

    }

    @FXML
    private void ColorWipeGREEN() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (btnG.getText().equals("Green")) {
            outputFITA.print('h');
            outputFITA.flush();
        }
//PASSAR ELSE PARA DESLIGAR
    }

    @FXML
    private void ColorWipeBLUE() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (btnB.getText().equals("Blue")) {
            outputFITA.print('i');
            outputFITA.flush();
        }
//PASSAR ELSE PARA DESLIGAR
    }

    @FXML
    private void ColorWipeWHITE() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (btnW.getText().equals("White")) {
            outputFITA.print('j');
            outputFITA.flush();
        }
//PASSAR ELSE PARA DESLIGAR
    }

}
