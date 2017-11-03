package hellormi;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface InterfaceHello extends Remote {
    String sayHello() throws RemoteException;
}