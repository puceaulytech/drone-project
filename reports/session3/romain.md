J'ai récupéré les modèles 3D du drone et j'ai lancé l'impressions des pièces au FabLab. J'ai lancé à peu près la moitié des pièces et la plaque est déjà bien chargé. (EDIT mardi 10 janvier 15:00: l'impression a apparement été un carnage et on a réussi à récupérer 3 pièces, on va tenter de relancer l'impression avec moins de pièces sur la plaque).

J'ai aussi commencer a programmer une classe C++ permettant de récupèrer les commandes radio PWM envoyées par la télécommande:

```cpp
#ifndef RECEIVER_HPP
#define RECEIVER_HPP

#define NB_CHANNEL 6

class Receiver {
  public:
    Receiver();
    void update(int channel);
    int getChannel(int channel);

  private:
    int m_values[NB_CHANNEL];
};

Receiver::Receiver() = default;

void Receiver::update(int channel) {
  m_values[channel] = pulseIn(channel, HIGH, 21 * 1000);
}

int Receiver::getChannel(int channel) {
  return m_values[channel];
}

#endif
```

Le problème étant que il faut faire à peu près 6 pulseIn et cela prend du temps, donc ça risque d'être un problème:
- Dans le cas où le drone est seulement manuel, on peut connecter la sortie PWM du récepteur radio directement à l'ESC/servo
- Quand on va ajouter un mode automatique (controlé par l'Arduino) alors il faudra un moyen d'envoyer nos propres commandes à l'ESC/servo, et pouvoir facilement basculer sur le mode manuel. (on a pensé à un multiplexeur ou porte logique, je sais plus trop, qui permettrait de basculer entre connection direct avec le récepteur radio et connection avec l'arduino, et donc éviter la latence du pulseIn)
