#include "WebTree.h"

using namespace std;

#define WEB_MAX(a, b) return (a) > (b) ? (a) : (b);

WebTree::WebTree()
		: root(nullptr) {}

WebTree::~WebTree() {
	deleteRec(root);
}

void WebTree::deleteRec(Node *node) {
	if (node) {
		deleteRec(node->left);
		deleteRec(node->right);
		delete node;
	}
}

void WebTree::insert(const Website &site) {
	if (root) insertRec(site, root);
	else root = new Node(new Website(site));
}

void WebTree::insertRec(const Website &site, Node *node) {
	if (*node->site > site.getKeyword()) { // left side
		if (node->left) insertRec(site, node->left);
		else node->left = new Node(new Website(site));
	} else if (*node->site < site.getKeyword()) { // right side
		if (node->right) insertRec(site, node->right);
		else node->right = new Node(new Website(site));
	}
	// if same, nothing happens
}

void WebTree::removeAll(const char *topic) {
	removeAllRec(topic, root);
}

void WebTree::removeAllRec(const char *topic, Node *&node) {
	if (node) {
		if (node->site->checkTopic(topic))
			remove(node);
		if (node) removeAllRec(topic, node->left);
		if (node) removeAllRec(topic, node->right);
	}
}

bool WebTree::remove(const char *keyword) {
	if (root) {
		root = remove(root, keyword);
		return true;
	}
	return false;
}

WebTree::Node* WebTree::remove(Node *node, const char *keyword) {
	if (node) {
		if (*node->site < keyword) node->right = remove(node->right, keyword);
		else if (*node->site > keyword) node->left = remove(node->left, keyword);
		else remove(node);
	}
	return node;
}

void WebTree::remove(Node *&node) {
	if (!node->left && !node->right) { // No children
		delete node;
		node = nullptr;
	} else if (!node->left && node->right) { // Only right
		Node *toDelete = node;
		node = node->right;
		delete toDelete;
	} else if (node->left && !node->right) { // Only left
		Node *toDelete = node;
		node = node->left;
		delete toDelete;
	} else { // Both children
		Node *toDelete = getMinNode(node->right);
		*node->site = *toDelete->site; // to call the Website::operator=(const Website&)
		node->right = remove(node->right, toDelete->site->getKeyword());
	}
}

WebTree::Node* WebTree::getMinNode(Node *node) const {
	return node->left ? getMinNode(node->left) : node;
}

bool WebTree::get(const char *keyword, Website &site) const {
	return getRec(keyword, site, root);
}

bool WebTree::getRec(const char *keyword, Website &site, Node *node) const {
	if (node) {
		if (node->site->checkKeyword(keyword)) {
			site = *node->site;
			return true;
		}
		if (getRec(keyword, site, node->left) || getRec(keyword, site, node->right)) return true;
	}
	return false;
}

WebTree::Node::Node(Website *site)
		: site(site), left(nullptr), right(nullptr) {}

WebTree::Node::~Node() {
	delete site;
}

std::ostream& operator<<(std::ostream &ostr, const WebTree &tree) {
	tree.printRec(ostr, tree.root);
	return ostr;
}

void WebTree::printRec(std::ostream &ostr, WebTree::Node *node) const {
	if (node) {
		printRec(ostr, node->left);
		ostr << *node->site;
		printRec(ostr, node->right);
	}
}
