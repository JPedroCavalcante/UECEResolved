package jdbc;

import javax.swing.JOptionPane;
public class TestConnection {
    public static void main(String[] args) {
        
         try {
             
             new ConnectionFactory().getConnection();
             JOptionPane.showMessageDialog(null, "Conectado com sucesso!");             
         } catch (Exception erro) {
              JOptionPane.showMessageDialog(null, "Algo deu errado! ocorreu o erro: "  + erro);    
         }
         
         
     }
    
}