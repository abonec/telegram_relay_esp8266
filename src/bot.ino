WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

void initBot()
{
    sendMessage(GROUIP, "ML relay bot is online now");
}

void sendMessage(String chatId, String message)
{
    bot.sendMessage(chatId, message, "");
}

void checkMessages()
{
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages)
    {
        handleNewMessages(numNewMessages);
        numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
}
void handleNewMessages(int numNewMessages)
{
    for (int i = 0; i < numNewMessages; i++)
    {
        String chat_id = String(bot.messages[i].chat_id);
        String text = bot.messages[i].text;

        String from_name = bot.messages[i].from_name;
        if (from_name == "")
        {
            from_name = "Guest";
        }

        if (text == "/turn_ml")
        {
            turnMLAction(chat_id);
        }
        else if (text == "/ping_ml")
        {
            pingAction(chat_id);
        }
        else
        {
            sendMessage(chat_id, "Can't handle " + text);
        }
    }
}