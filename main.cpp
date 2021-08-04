#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
using namespace std;

sf::TcpSocket* getServerSocket(unsigned short port) {
    sf::IpAddress server;
    do
    {
        std::cout << "Type the address or name of the server to connect to: ";
        std::cin >> server;
    } while (server == sf::IpAddress::None);

    // Create a socket for communicating with the server
    sf::TcpSocket* socket = new sf::TcpSocket;

    // Connect to the server
    if (socket->connect(server, port) != sf::Socket::Done)
        return nullptr;
    std::cout << "Connected to server " << server << std::endl;

    // Receive a message from the server
    char in[128];
    std::size_t received;
    if (socket->receive(in, sizeof(in), received) != sf::Socket::Done)
        return nullptr;
    std::cout << "Message received from the server: \"" << in << "\"" << std::endl;
    return socket;
}
void sendToServer(string message, sf::TcpSocket* socket) {

    if (socket->send(message.c_str(), message.length() + 1) != sf::Socket::Done)
        return;
    std::cout << "Message sent to the MAIN server: \"" << message << "\"" << std::endl;
}
int main()
{

    const unsigned short port = 50001;
    sf::TcpSocket* socket;
    socket = getServerSocket(port);
    while (socket == nullptr) {
        socket = getServerSocket(port);
    }
    string message = "";

    cin >> message;
    sendToServer(message, socket);



    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Yellow);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}