#include "menu_scene.hpp"

void MenuScene::game_logic(){

    //pega objeto menuFire
    GameObject* fireMenu = &get_game_object("menuFire");

    //define a posicao do fogona tela
    fireMenu->main_positionX = 690;
    fireMenu->main_positionY = 470;

    //Gerenciando botões na cena
    buttons_controller();

}

void MenuScene::buttons_controller(){
    //pega gameobject bNew
    GameObject* bNew = &get_game_object("bNew");
    //define a posicao do botao novo jogo na tela
    bNew->main_positionX = 300;
    bNew->main_positionY = 275;

    //pega gameobject bLoad
    GameObject* bLoad = &get_game_object("bLoad");
    //define a posicao do botao de load na tela
    bLoad->main_positionX = 800;
    bLoad->main_positionY = 820;

    //pega componentes de animacao do botao novo e do botao load
    Animation* bnewAnimation = (dynamic_cast<Animation *>(bNew->get_component("imageBNew")));
    Animation* bloadAnimation = (dynamic_cast<Animation *>(bLoad->get_component("imageBLoad")));

    AudioComponent* button_hover_sound = (dynamic_cast<AudioComponent*>(bLoad->get_component("button_hover_sound")));
    //Faz efeito de passar o mause em cima
    if(Game::instance.keyboard->isKeyDown("enter")){
        Game::instance.change_scene("initial_story");
    }

    if(Game::instance.mouse->is_over(bNew)){
        if (Game::instance.mouse->is_right_button()) {
            //Game::instance.change_scene("Fase 1");
            Game::instance.change_scene("initial_story");
        }
        bnewAnimation->useAnimation("normal");
        button_hover_sound->play(0,-1);
    }
    else{
        bnewAnimation->useAnimation("mouseON");
    }
    if(Game::instance.mouse->is_over(bLoad)){
        bloadAnimation->useAnimation("normal");
    }
    else{
        bloadAnimation->useAnimation("mouseON");
    }

}

MenuScene::~MenuScene(){}
