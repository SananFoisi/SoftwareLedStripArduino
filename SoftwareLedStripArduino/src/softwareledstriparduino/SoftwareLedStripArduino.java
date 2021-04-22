/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package softwareledstriparduino;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

/**
 *
 * @author rhyan
 */
public class SoftwareLedStripArduino extends Application {

    @Override
    public void start(Stage stage) throws Exception {

        Parent root = FXMLLoader.load(getClass().getResource("/view/FXMLDocument.fxml"));

        Scene scene = new Scene(root);

        stage.setResizable(false);
        stage.getIcons().add(new Image(getClass().getResourceAsStream("/view/rainbow.png")));
        stage.setTitle("LED Strip Monitor!");
        stage.setScene(scene);
        stage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

}
