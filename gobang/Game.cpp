#include "Game.h"
#include <iostream>

Game::Game():window(sf::VideoMode(860,860),"Gobang Game"),board(16,16,holder)
{
    holder.LoadTexture(ResourceHolder::ResourceId::RESOURCE_CHESSBOARD,"../gobang/resources/board.jpeg");
    holder.LoadTexture(ResourceHolder::ResourceId::RESOURCE_BLACK_CHESS,"../gobang/resources/black.png");
    holder.LoadTexture(ResourceHolder::ResourceId::RESOURCE_WHITE_CHESS,"../gobang/resources/white.png");

    board.setRect(sf::Vector2f(0.f,0.f),sf::Vector2f(window.getSize().x,window.getSize().y));
    board.setPadding(30.f);
    board.Init();

    InitGame();
}

void Game::Run()
{
    while (window.isOpen())
    {
        ProcessEvent();
        Update();
        Render();
    }
}

void Game::ProcessEvent() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button==sf::Mouse::Button::Left) PutChessPiece(sf::Vector2i(event.mouseButton.x,event.mouseButton.y));
                break;
            default:
                break;
        }
    }
}

void Game::Update() {

}

void Game::Render() {
    window.clear();
    window.draw(board);

    window.display();
}


void Game::InitGame() {
    window.clear();
    window.draw(board);

    window.display();
}


void Game::PutChessPiece(sf::Vector2i pos) {
    auto ret = board.Put(pos,GobangChessPiece::ChessType::BlackChess);
    if (ret==board.Win)
    {

    }
//    switch (ret)
//    {
//        case board.Win:
//        std::cout<<"suc"<<std::endl;
//            break;
//        default:
//            break;
//
//    }
}

