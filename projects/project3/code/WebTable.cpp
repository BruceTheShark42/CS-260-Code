#include "WebTable.h"
#include <cstring>

using namespace std;

#define NUM_HASHES 251

WebTable::WebTable()
		: entries(new Node*[NUM_HASHES]) {
	for (size_t i = 0; i < NUM_HASHES; ++i)
		entries[i] = new Node();
	// FYI: I've been using dummy nodes for all of my implementations,
	// which is why I didn't "check if head was null": I didn't have to.
}

WebTable::~WebTable() {
	for (size_t i = 0; i < NUM_HASHES; ++i) {
		for (Node *node = entries[i], *next; node != nullptr; node = next) {
			next = node->next;
			delete node;
		}
	}
	delete[] entries;
}

bool WebTable::add(const char *key, const Website &site) {
	new Node(entries[hash(key)], new Website(site));
}

Website* WebTable::get(const char *key, size_t &count) const {
	Node *list = entries[hash(key)];
	if (list->next == nullptr)
		return nullptr;
	
	count = 1;
	for (Node *node = list->next->next; node != nullptr; node = node->next, ++count);
	Website *sites = new Website[count];
	
	size_t i = 0;
	for (Node *node = list->next; node != nullptr; sites[i++] = *node->site, node = node->next);
	return sites;
}

bool WebTable::set(const char *key, const Website &site) {
	for (Node *node = entries[hash(key)]->next; node != nullptr; node = node->next) {
		Website *website = node->site;
		if (website->checkURL(site.getURL())) {
			website->setReview(site.getReview());
			website->setRating(site.getRating());
			return true;
		}
	}
	return false;
}

void WebTable::cull() {
	for (size_t i = 0; i < NUM_HASHES; ++i) {
		for (Node *node = entries[i]; node->next != nullptr; ) {
			if (node->next->site->getRating() == 1) {
				Node *toDelete = node->next;
				node->next = node->next->next;
				delete toDelete;
			} else {
				node = node->next;
			}
		}
	}
}

void WebTable::print(ostream &ostr, const char *key) const {
	printRec(ostr, entries[hash(key)]->next);
}

void WebTable::printRec(ostream &ostr, Node *node) const {
	if (node != nullptr) {
		ostr << *node->site;
		printRec(ostr, node->next);
	}
}

size_t WebTable::hash(const char *key) const {
	if (key == nullptr)
		return 0;
	size_t len = strlen(key);
	if (!len)
		return 1;
	
	size_t sum = 0, indexSum = 0;
	for (size_t i = 0; i < len; indexSum += ++i)
		sum += (i + 1) * key[i];
	return (sum * indexSum) % NUM_HASHES;
}

WebTable::Node::Node(Website *site, Node *node)
		: site(site), next(node) {}

WebTable::Node::Node(Node *prev, Website *site)
		: site(site), next(prev->next) {
	prev->next = this;
}

WebTable::Node::~Node() {
	if (site != nullptr) delete site;
}

ostream& operator<<(ostream &ostr, const WebTable &table) {
	ostr << "Websites:\n";
	for (size_t i = 0; i < NUM_HASHES; ++i)
		for (WebTable::Node *node = table.entries[i]->next; node != nullptr; node = node->next)
			ostr << *node->site;
	return ostr;
}
