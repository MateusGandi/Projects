import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionFactory {
//factory para reduzir acoplamento em software
    public Connection recuperarConexão() throws ClassNotFoundException {
        //Class.forName("com.mysql.jdbc.Driver");
        try{
            return DriverManager
                    .getConnection("jdbc:mysql://localhost:3306/crud_db?user=root&password=gandimateus");//url
        }catch (SQLException e) {
            throw  new RuntimeException(e);
        }
    }
}
