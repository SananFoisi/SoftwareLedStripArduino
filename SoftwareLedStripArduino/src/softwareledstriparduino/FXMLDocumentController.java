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
    private char ColorWipe = '0';
    private char RainbowCycle = '0';
    private char Rainbow = '0';
    private char Random = '0';
    private char FadeInOut = '0';
    private char RunningLights = '0';

    //botao ColorWipe COR (btn CW COR)
    @FXML
    private Button btnCWB;
    @FXML
    private Button btnCWC;
    @FXML
    private Button btnCWG;
    @FXML
    private Button btnCWM;
    @FXML
    private Button btnCWR;
    @FXML
    private Button btnCWW;

    //botao efeito (btn EFEITO)
    @FXML
    private Button btnRC;
    @FXML
    private Button btnRB;
    @FXML
    private Button btnFIO;
    @FXML
    private Button btnRA;

    //botao RunningLights COR (btn RLR COR)
    @FXML
    private Button btnRLR;
    @FXML
    private Button btnRLG;
    @FXML
    private Button btnRLB;
    @FXML
    private Button btnRLW;

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

        if (btnReset.getText().equals("Desligar")) {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    /**
     * ColorWipe
     *
     */
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
    private void ColorWipeCIAN() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (ColorWipe == '0' || ColorWipe != '0') {
            outputFITA.print('a');
            outputFITA.flush();
            ColorWipe = 'a';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            ColorWipe = '0';
        }

        if (btnCWC.getText().equals("Ciano")) {
            outputFITA.print('j');
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
            outputFITA.print('b');
            outputFITA.flush();
            ColorWipe = 'b';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            ColorWipe = '0';
        }

        if (btnCWG.getText().equals("Green")) {
            outputFITA.print('k');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    @FXML
    private void ColorWipeMAGENTA() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (ColorWipe == '0' || ColorWipe != '0') {
            outputFITA.print('c');
            outputFITA.flush();
            ColorWipe = 'c';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            ColorWipe = '0';
        }

        if (btnCWM.getText().equals("Magenta")) {
            outputFITA.print('l');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    @FXML
    private void ColorWipeRED() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (ColorWipe == '0' || ColorWipe != '0') {
            outputFITA.print('d');
            outputFITA.flush();
            ColorWipe = 'd';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            ColorWipe = '0';
        }

        if (btnCWR.getText().equals("Red")) {
            outputFITA.print('m');
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
            outputFITA.print('e');
            outputFITA.flush();
            ColorWipe = 'e';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            ColorWipe = '0';
        }

        if (btnCWW.getText().equals("White")) {
            outputFITA.print('n');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    /**
     * EFEITOS
     *
     */
    @FXML
    private void RainbowCycle() {
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
    private void Rainbow() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (Rainbow == '0' || Rainbow != '0') {
            outputFITA.print('2');
            outputFITA.flush();
            Rainbow = '2';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            Rainbow = '0';
        }
        if (btnRB.getText().equals("Rainbow")) {
            outputFITA.print('b');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    @FXML
    private void FadeInOut() {
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

    @FXML
    private void Random() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (Random == '0' || Random != '0') {
            outputFITA.print('4');
            outputFITA.flush();
            Random = '4';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            Random = '0';
        }
        if (btnRA.getText().equals("Random")) {
            outputFITA.print('d');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    /**
     * RunningLights
     *
     */
    @FXML
    private void RunningLightsRED() {
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

        if (btnRLR.getText().equals("Red")) {
            outputFITA.print('e');
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
            outputFITA.print('6');
            outputFITA.flush();
            RunningLights = '6';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            RunningLights = '0';
        }

        if (btnRLG.getText().equals("Green")) {
            outputFITA.print('f');
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
            outputFITA.print('7');
            outputFITA.flush();
            RunningLights = '7';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            RunningLights = '0';
        }

        if (btnRLB.getText().equals("Blue")) {
            outputFITA.print("g");
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

    @FXML
    private void RunningLightsWHITE() {
        PrintWriter outputFITA = new PrintWriter(porta.getOutputStream());

        if (RunningLights == '0' || RunningLights != '0') {
            outputFITA.print('8');
            outputFITA.flush();
            RunningLights = '8';
        } else {
            outputFITA.print('0');
            outputFITA.flush();
            RunningLights = '0';
        }

        if (btnRLW.getText().equals("White")) {
            outputFITA.print('h');
            outputFITA.flush();
        } else {
            outputFITA.print('0');
            outputFITA.flush();
        }
    }

}
