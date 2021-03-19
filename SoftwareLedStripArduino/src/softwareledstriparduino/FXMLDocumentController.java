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
import javafx.scene.control.Accordion;
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
    private Accordion menuEfeitos;

    @FXML
    private Button btnReset;

    private SerialPort porta;
    private char RainbowCycle = '0';
    private char RGBLoop = '0';
    private char FadeInOut = '0';
    private char RunningLights = '0';
    private char ColorWipe = '0';

    //botao efeito (btn EFEITO)
    @FXML
    private Button btnRC;
    @FXML
    private Button btnRGB;
    @FXML
    private Button btnFIO;

    //botao RunningLights COR (btn RLR COR)
    @FXML
    private Button btnRLR;
    @FXML
    private Button btnRLG;
    @FXML
    private Button btnRLB;

    //botao ColorWipe COR (btn CW COR)
    @FXML
    private Button btnCWR;
    @FXML
    private Button btnCWG;
    @FXML
    private Button btnCWB;
    @FXML
    private Button btnCWW;

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        carregarPortas();
        menuEfeitos.setDisable(true);

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

            menuEfeitos.setDisable(false);

            if (porta.openPort()) {
                btnConectar.setText("Desconectar");
                cbPortas.setDisable(true);
            }
        } else {
            porta.closePort();
            cbPortas.setDisable(false);
            btnConectar.setText("Conectar");
            menuEfeitos.setDisable(true);
        }
    }

    @FXML
    private void reset() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (btnReset.getText().equals("Reset")) {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    /**
     * EFEITOS
     *
     */
    @FXML
    private void ligarRainbowCycle() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (RainbowCycle == '0' || RainbowCycle != '0') {
            outputFITA.print('1');
            outputFITA.flush();
            RainbowCycle = '1';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            RainbowCycle = '0';
        }
        if (btnRC.getText().equals("Rainbow Cycle")) {
            outputFITA.print('a');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    @FXML
    private void ligarRGBLoop() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (RGBLoop == '0' || RGBLoop != '0') {
            outputFITA.print('2');
            outputFITA.flush();
            RGBLoop = '2';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            RGBLoop = '0';
        }
        if (btnRGB.getText().equals("RGB Loop")) {
            outputFITA.print('b');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    @FXML
    private void ligarFadeInOut() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (FadeInOut == '0' || FadeInOut != '0') {
            outputFITA.print('3');
            outputFITA.flush();
            FadeInOut = '3';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            FadeInOut = '0';
        }
        if (btnFIO.getText().equals("Fade In Out")) {
            outputFITA.print('c');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    /* MERDAS */
    /**
     * RunningLights
     *
     */
    @FXML
    private void RunningLightsRED() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (RunningLights == '0' || RunningLights != '0') {
            outputFITA.print('4');
            outputFITA.flush();
            RunningLights = '4';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            RunningLights = '0';
        }

        if (btnRLR.getText().equals("Red")) {
            outputFITA.print('d');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    @FXML
    private void RunningLightsGREEN() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (RunningLights == '0' || RunningLights != '0') {
            outputFITA.print('5');
            outputFITA.flush();
            RunningLights = '5';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            RunningLights = '0';
        }

        if (btnRLG.getText().equals("Green")) {
            outputFITA.print('e');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    @FXML
    private void RunningLightsBLUE() {

        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());
        if (RunningLights == '0' || RunningLights != '0') {
            outputFITA.print('6');
            outputFITA.flush();
            RunningLights = '5';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            RunningLights = '0';
        }

        if (btnRLB.getText().equals("Blue")) {
            outputFITA.print("f");
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    /**
     * ColorWipe
     *
     */
    @FXML
    private void ColorWipeRED() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (ColorWipe == '0' || ColorWipe != '0') {
            outputFITA.print('7');
            outputFITA.flush();
            ColorWipe = '7';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            ColorWipe = '0';
        }

        if (btnCWR.getText().equals("Red")) {
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

        if (ColorWipe == '0' || ColorWipe != '0') {
            outputFITA.print('8');
            outputFITA.flush();
            ColorWipe = '8';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            ColorWipe = '0';
        }

        if (btnCWG.getText().equals("Green")) {
            outputFITA.print('h');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }

    }

    @FXML
    private void ColorWipeBLUE() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (ColorWipe == '0' || ColorWipe != '0') {
            outputFITA.print('9');
            outputFITA.flush();
            ColorWipe = '9';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            ColorWipe = '0';
        }

        if (btnCWB.getText().equals("Blue")) {
            outputFITA.print('i');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }

    }

    @FXML
    private void ColorWipeWHITE() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (ColorWipe == '0' || ColorWipe != '0') {
            outputFITA.print('z');
            outputFITA.flush();
            ColorWipe = 'z';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            ColorWipe = '0';
        }

        if (btnCWW.getText().equals("White")) {
            outputFITA.print('j');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }

    }

}
