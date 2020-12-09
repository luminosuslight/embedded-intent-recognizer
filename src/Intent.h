#ifndef INTENT_H
#define INTENT_H

#include <map>
#include <regex>
#include <string>
#include <vector>

struct PatternRegex {
    int maxScore = 0;
    std::regex regex;
    std::map<int, std::string> namedGroups;
};


class Intent
{
public:
    /**
     * @brief Intent repsents the intent an utterance can have
     * @param name a short descriptive name
     * @param patterns a list of patterns that are used to find phrases that match this intent
     *
     * The patterns are interpreted as regular expressions. In addition, there are three convenience keywords:
     * - <word> is a placeholder for a single abtritary word
     * - <text> is a placeholder for abritary text and includes the empty word
     * - <attribute_name:[word|text]> can be used to store attributes from an input phrase and retreive
     * them later.
     *
     * The patterns are OR connected: if one matches, this intent will have a high score.
     * The score depends on the length of the matched pattern. If one intent matches a short pattern and another
     * matches using a much longer pattern on the same input phrase, the latter intent is chosen.
     */
    Intent(const std::string &name, const std::vector<std::string> &patterns);

    const std::string &getName() const;

    /**
     * @brief Intent::getScore returns a score that says how well this intent suits the input phrase
     * @param phrase the input phrase
     * @return a score greater than or equal 0
     */
    double getScore(const std::string &phrase) const;

    /**
     * @brief getAttributes returns the attributes contained in a matching input phrase
     * @param phrase the input phrase
     * @return a map with attribute name - attribute value pairs
     */
    std::map<std::string, std::string> getAttributes(const std::string &phrase) const;

private:
    /**
     * @brief Intent::compilePatternsToRegexes compiles the domain specific language used for the patterns to
     * actual regex instances.
     */
    void compilePatternsToRegexes();

protected:
    std::string m_name;
    std::vector<std::string> m_patterns;
    std::vector<PatternRegex> m_patternRegexes;
};

#endif // INTENT_H
