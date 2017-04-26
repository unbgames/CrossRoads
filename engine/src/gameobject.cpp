#include "gameobject.hpp"
#include "components/image.hpp"

using namespace engine;

bool GameObject::init(){
    Log::instance.info("Init game object");

    //Iterando o mapa de componentes, passando por cada tipo de componente.
    for(auto id_componentList: main_components){
        //Iterando a lista de componentes do tipo encontrado.
        for(auto component:id_componentList.second){
            if(component->state() == Component::State::enabled && component->init() == false)
                return false;
        }
    }

    return true;
}

bool GameObject::shutdown(){
    Log::instance.info("Shutdown game object");

    //Iterando o mapa de componentes, passando por cada tipo de componente.
    for(auto id_componentList: main_components){
        //Iterando a lista de componentes do tipo encontrado.
        for(auto component:id_componentList.second){
            if(component->state() == Component::State::enabled && component->shutdown() == false)
                return false;
        }
    }

    return true;
}

bool GameObject::draw(){
  //TODO --> VALIDAR RETURN
    //Procurando no mapa os componentes do tipo ImageComponent
    for(auto component: main_components[std::type_index(typeid(ImageComponent))]){
        /*Caso o componente encontrado esteja com estado habilitado, converte ele para um componente de imagem
        e o desenha na tela*/
        if(component->state() == Component::State::enabled)
            (dynamic_cast<ImageComponent *>(component))->draw();
    }
    return true;
    //
    // for(auto component: main_components[std::type_index(typeid(TextComponent))]){
    //     /*Caso o componente encontrado esteja com estado habilitado, converte ele para um componente de texto
    //     e o desenha na tela*/
    //     if(component->state() == Component::State::enabled)
    //         (dynamic_cast<TextComponent *>(component))->draw();
    // }
}

bool GameObject::add_component(Component &component){
  //TODO ->> VALIDAR RETURN
    Log::instance.info("Adding components to game object");
    //Adiciona o componente no fim da lista referente ao tipo do mesmo.
    main_components[std::type_index(typeid(component))].push_back(&component);
    return true;
}
