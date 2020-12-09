#ifndef INTENT_H
#define INTENT_H

#include <vector>
#include <string>
#include <regex>

class Intent
{
public:
    Intent(const std::string &name, const std::vector<std::string> &patterns);

    double getScore(const std::string &phrase) const;

private:
    void compilePatternsToRegexes();

protected:
    std::string m_name;
    std::vector<std::string> m_patterns;
    std::vector<std::regex> m_patternRegexes;
};

#endif // INTENT_H
