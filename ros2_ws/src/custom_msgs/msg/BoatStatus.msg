# Intestazione standard (utile per timestamp e frame_id)
std_msgs/Header header

# Stato generale della barca
string status         # es: "Navigating", "Docked", "Error"

# Livello batteria in percentuale
float32 battery_level

# Flag per sapere se siamo in guida autonoma o manuale
bool is_autonomous