package hellormi;


import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
        
public class Server implements InterfaceHello {
        
    public Server() {}

    public String sayHello() {
        return "Ola, Mundo!";
    }
        
    public static void main(String args[]) {
        
        try {
        	/**
        	 * The main method of the server needs to create the remote object that provides
        	 *  the service. Additionally, the remote object must be exported to the 
        	 *  Java RMI runtime so that it may receive incoming remote calls. 
        	 */
            Server obj = new Server();
            InterfaceHello stub = (InterfaceHello) UnicastRemoteObject.exportObject(obj, 0);
            
            // Bind the remote object's stub in the registry
            Registry registry = LocateRegistry.getRegistry();
            registry.bind("Hello", stub);

            System.err.println("Executando Servidor");
        }
        catch (RemoteException r){
        	System.err.println("Server exception: " + r.toString());
            r.printStackTrace();
        }
        catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }
}