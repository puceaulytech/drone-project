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
