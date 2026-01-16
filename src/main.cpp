// Include the necessary libraries
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

int main() {
  // Initialize the window
  const sf::VideoMode windowSpecification({1920u, 1080u});
  auto window = sf::RenderWindow(windowSpecification, "Chess");

  // Set Window Icon
  const sf::Image icon("assets/icon.png");
  window.setIcon(icon);

  // Set the Frame limit
  window.setFramerateLimit(144);

  // Set the minimum size
  const std::optional<sf::Vector2u> minimumSize({1020u, 550u});
  window.setMinimumSize(minimumSize);

  // Load all the pieces
  sf::Texture chessPieces("assets/chessPieces.png");

  // Load all the pieces into different sprites
  // The first arguement specifies which texture
  // Second tells two things:
  // // first position
  // // second size
  // Also, setting their origin to their center for ease of use
  sf::Vector2i size(64, 64);
  sf::Vector2f origin(32, 32);
  sf::Sprite whitePawn(chessPieces, {{320, 0}, size}),
      whiteKing(chessPieces, {{0, 0}, size}),
      whiteQueen(chessPieces, {{64, 0}, size}),
      whiteBishop(chessPieces, {{128, 0}, size}),
      whiteKnight(chessPieces, {{192, 0}, size}),
      whiteRook(chessPieces, {{256, 0}, size}),
      blackPawn(chessPieces, {{320, 64}, size}),
      blackKing(chessPieces, {{0, 64}, size}),
      blackQueen(chessPieces, {{64, 64}, size}),
      blackBishop(chessPieces, {{128, 64}, size}),
      blackKnight(chessPieces, {{192, 64}, size}),
      blackRook(chessPieces, {{256, 64}, size});
  whitePawn.setOrigin(origin);
  whiteKing.setOrigin(origin);
  whiteQueen.setOrigin(origin);
  whiteBishop.setOrigin(origin);
  whiteKnight.setOrigin(origin);
  whiteRook.setOrigin(origin);
  blackPawn.setOrigin(origin);
  blackKing.setOrigin(origin);
  blackQueen.setOrigin(origin);
  blackBishop.setOrigin(origin);
  blackKnight.setOrigin(origin);
  blackRook.setOrigin(origin);

  // Loading the Chess Board
  sf::Texture chessBoardLoad("assets/chessBoard.png");
  sf::Sprite chessBoard(chessBoardLoad, {{0, 0}, {512, 512}});

  // Set the origin of chess board to its center
  // and the position it in the center of the screen
  chessBoard.setOrigin({256, 256});
  chessBoard.setPosition(
      {(float)window.getSize().x / 2, (float)window.getSize().y / 2});

  // Run the loop while the window is open
  while (window.isOpen()) {

    // look for window events
    while (const std::optional event = window.pollEvent()) {

      // If the window close button is pressed
      if (event->is<sf::Event::Closed>()) {

        // Close the window
        window.close();
      }
    }

    // Clear the previous frame with a new color
    window.clear(sf::Color::Cyan);

    window.draw(chessBoard);

    // Display the window output buffer
    window.display();
  }
}
