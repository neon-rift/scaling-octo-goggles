//!-- Include the necessary libraries --!
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <algorithm>
#include <cctype>
#include <string>

enum GameMode { MAIN_MENU,
    PLAYING,
    RETRY_MENU };

enum GameColor {
    BLACK,
    WHITE
};

int main()
{
    // Initialize the window
    const sf::VideoMode windowSpecification({ 1920u, 1080u });
    auto window = sf::RenderWindow(windowSpecification, "Chess");

    // Set Window Icon
    const sf::Image icon("assets/icon.png");
    window.setIcon(icon);

    // Set the Frame limit
    window.setFramerateLimit(144);

    // Set the minimum size
    const std::optional<sf::Vector2u> minimumSize({ 1020u, 550u });
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
    sf::Sprite whitePawn(chessPieces, { { 320, 0 }, size }),
        whiteKing(chessPieces, { { 0, 0 }, size }),
        whiteQueen(chessPieces, { { 64, 0 }, size }),
        whiteBishop(chessPieces, { { 128, 0 }, size }),
        whiteKnight(chessPieces, { { 192, 0 }, size }),
        whiteRook(chessPieces, { { 256, 0 }, size }),
        blackPawn(chessPieces, { { 320, 64 }, size }),
        blackKing(chessPieces, { { 0, 64 }, size }),
        blackQueen(chessPieces, { { 64, 64 }, size }),
        blackBishop(chessPieces, { { 128, 64 }, size }),
        blackKnight(chessPieces, { { 192, 64 }, size }),
        blackRook(chessPieces, { { 256, 64 }, size });
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
    sf::Texture chessBoardLoad("assets/rect-8x8.png");
    sf::Sprite chessBoard(chessBoardLoad, { { 0, 0 }, { 512, 512 } });

    // Set the origin of chess board to its center
    // and the position it in the center of the screen
    chessBoard.setOrigin({ 256, 256 });
    chessBoard.setPosition({ (float)window.getSize().x / 2, (float)window.getSize().y / 2 });

    // Reverse ChessBoard
    sf::Sprite chessBoardReversed = chessBoard;
    chessBoardReversed.setOrigin({ 256, 256 });
    chessBoardReversed.setPosition({ (float)window.getSize().x / 2, (float)window.getSize().y / 2 });
    chessBoardReversed.setRotation(sf::Angle(sf::degrees(180.f)));

    // Starting Position
    std::string FEN = "8/5k2/3p4/1p1Pp2p/pP2Pp1P/P4P1K/8/8";
    std::string reverseFEN = FEN;

    // Top left square Center position
    sf::Vector2f topLeftSquare({ (float)((float)window.getSize().x / 2 - (3.5 * 64)), (float)((float)window.getSize().y / 2 - (3.5 * 64)) });

    // Making a copy to modify the position of pieces
    sf::Vector2f currentPosition = topLeftSquare;

    // Set the intial game mode.
    GameMode current = PLAYING;

    // Which color you chose:
    int colorMode = GameColor::WHITE;

    // sets up a reverse fen string for the case you are playing as black
    std::reverse(reverseFEN.begin(), reverseFEN.end());

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

        // Game Logic
        if (current == GameMode::PLAYING) {
            if (colorMode == GameColor::WHITE) {
                window.draw(chessBoard);
                for (char c : FEN) {
                    if (c == '/') {
                        currentPosition.y += 64;
                        currentPosition.x = topLeftSquare.x;
                    } else if (std::isdigit(c)) {
                        currentPosition.x += (c - '0') * 64;
                    } else if (c == 'r') {
                        blackRook.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(blackRook);
                    } else if (c == 'n') {
                        blackKnight.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(blackKnight);
                    } else if (c == 'b') {
                        blackBishop.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(blackBishop);
                    } else if (c == 'q') {
                        blackQueen.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(blackQueen);
                    } else if (c == 'k') {
                        blackKing.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(blackKing);
                    } else if (c == 'R') {
                        whiteRook.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(whiteRook);
                    } else if (c == 'N') {
                        whiteKnight.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(whiteKnight);
                    } else if (c == 'B') {
                        whiteBishop.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(whiteBishop);
                    } else if (c == 'Q') {
                        whiteQueen.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(whiteQueen);
                    } else if (c == 'K') {
                        whiteKing.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(whiteKing);
                    } else if (c == 'P') {
                        whitePawn.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(whitePawn);
                    } else if (c == 'p') {
                        blackPawn.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(blackPawn);
                    }
                }

                currentPosition = topLeftSquare;
            } else if (colorMode == GameColor::BLACK) {
                window.draw(chessBoardReversed);
                for (char c : reverseFEN) {
                    if (c == '/') {
                        currentPosition.y += 64;
                        currentPosition.x = topLeftSquare.x;
                    } else if (std::isdigit(c)) {
                        currentPosition.x += (c - '0') * 64;
                    } else if (c == 'r') {
                        blackRook.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(blackRook);
                    } else if (c == 'n') {
                        blackKnight.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(blackKnight);
                    } else if (c == 'b') {
                        blackBishop.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(blackBishop);
                    } else if (c == 'q') {
                        blackQueen.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(blackQueen);
                    } else if (c == 'k') {
                        blackKing.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(blackKing);
                    } else if (c == 'R') {
                        whiteRook.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(whiteRook);
                    } else if (c == 'N') {
                        whiteKnight.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(whiteKnight);
                    } else if (c == 'B') {
                        whiteBishop.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(whiteBishop);
                    } else if (c == 'Q') {
                        whiteQueen.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(whiteQueen);
                    } else if (c == 'K') {
                        whiteKing.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(whiteKing);
                    } else if (c == 'P') {
                        whitePawn.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(whitePawn);
                    } else if (c == 'p') {
                        blackPawn.setPosition(currentPosition);
                        currentPosition.x += 64;
                        window.draw(blackPawn);
                    }
                }

                currentPosition = topLeftSquare;
            }

        }

        // UI Main Menu
        else if (current == GameMode::MAIN_MENU) {

        }

        // UI Retry Menu
        else if (current == GameMode::RETRY_MENU) {

        }

        // Error Condition
        else {
        }

        // Display the window output buffer
        window.display();
    }
}
