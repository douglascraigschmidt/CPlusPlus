#ifndef _TREE_STATE_H_
#define _TREE_STATE_H_

#include <string>
#include <iostream>
#include <map>

// Forward declaration.
class Expression_Tree_Context;

/**
 * @class Expression_Tree_State
 * @brief Implementation of the State pattern that is used to define 
 *        the various states that affect how users operations are
 *        processed.   
 * 
 *        Plays the role of the "state" base class in the State
 *        pattern that is used as the basis for the subclasses that
 *        actually define the various user operation states.
 */
class Expression_Tree_State
{
public:
  /// Exception class for Invalid States exceptions
  class Invalid_State : public std::domain_error
  {
  public:
    Invalid_State(const std::string &message) : std::domain_error(message) {}
  }; 

  /// Set the desired format to the designated @a new_format, updating
  /// the state of the @context accordingly.
  virtual void format (Expression_Tree_Context &context, 
                       const std::string &new_format);

  /// Make an expression tree based on the designated @a expression
  /// using the previously designated format, updating the state of
  /// the @context accordingly.
  virtual void make_tree (Expression_Tree_Context &context,
                          const std::string &expression);

  /// Print the most recently created expression tree using the
  /// designated @a format, updating the state of the @context
  /// accordingly.
  virtual void print (Expression_Tree_Context &context,
                      const std::string &format);

  /// Evaluate the "yield" of the most recently created expression
  /// tree using the designated @a format, updating the state of the
  /// @context accordingly.
  virtual void evaluate (Expression_Tree_Context &context,
                         const std::string &format);

  /// Print the operators and operands of the @a tree to the @os in
  /// the designated @a traversal_order.
  static void print_tree (const Expression_Tree &tree,
                          const std::string &traversal_order,
                          std::ostream &os);

  /// Evaluate and print the yield of the @a tree to the @os in the
  /// designated @a traversal_order.
  static void evaluate_tree (const Expression_Tree &tree, 
                             const std::string &traversal_order,
                             std::ostream &os);
};

/**
 * @class Uninitialized_State
 * @brief This is the initial state, which only allows @a format commands.
 */
class Uninitialized_State : public Expression_Tree_State
{
public:
  /// Sets the @a context's state to correspond to the designated @a
  /// new_format, e.g., @a Pre_Order_Uninitialized_State, @a
  /// Post_Order_Uninitialized_State, @a In_Order_Uninitialized_State,
  /// or @a Level_Order_Uninitialized_State.
  virtual void format (Expression_Tree_Context &context, 
                       const std::string &new_format);

private:
  /**
   * @class Uninitialized_State_Factory
   * @brief Implementation of a factory pattern that dynamically
   *        allocates the appropriate @a Expression_Tree_State object. 
   * 
   *        This is a variant of the Abstract Factory pattern that has a
   *        set of related factory methods but which doesn't use
   *        inheritance.
   */
  class Uninitialized_State_Factory
  {
  public:
    /// Constructor.
    Uninitialized_State_Factory (void);

    /// Dynamically allocate a new @a Expression_Tree_State
    /// object based on the designated @a traversal_order and @a end_iter.
    static Expression_Tree_State *make_uninitialized_state (const std::string &format);

  private:
    /// Dynamically allocate a new @a Level_Order_Uninitialized_State
    /// object based on the designated @a end_iter.
    static Expression_Tree_State *make_in_order_uninitialized_state (void);

    /// Dynamically allocate a new @a Pre_Order_Uninitialized_State
    /// object based on the designated @a end_iter.
    static Expression_Tree_State *make_pre_order_uninitialized_state (void);

    /// Dynamically allocate a new @a Post_Order_Uninitialized_State
    /// object based on the designated @a end_iter.
    static Expression_Tree_State *make_post_order_uninitialized_state (void);

    /// Dynamically allocate a new @a Level_Order_Uninitialized_State
    /// object based on the designated @a end_iter.
    static Expression_Tree_State *make_level_order_uninitialized_state (void);

    typedef Expression_Tree_State *(*UNINITIALIZED_STATE_PTF) (void);
    typedef std::map <std::string, UNINITIALIZED_STATE_PTF> UNINITIALIZED_STATE_MAP;

    static UNINITIALIZED_STATE_MAP uninitialized_state_map_;
  };

  static Uninitialized_State_Factory uninitialized_state_factory;
};

/**
 * @class Pre_Order_Uninitialized_State
 * @brief Now that the user has provided a format command
 *        indicating "pre-order" input this state will interpret the 
 *        subsequent expression accordingly.
 */
class Pre_Order_Uninitialized_State : public Uninitialized_State
{
public:
  /// Process the @a expression using a pre-order interpreter and
  /// update the state of the @a context to the @a
  /// Pre_Order_Initialized_State.  
  virtual void make_tree (Expression_Tree_Context &context,
                          const std::string &expression);
};

/**
 * @class Pre_Order_Initialized_State
 * @brief Now that the user has provided a expr command this state
 *        will print or evaluate the subsequent expression
 *        accordingly. 
 */
class Pre_Order_Initialized_State : public Pre_Order_Uninitialized_State
{
public:
  /// Print the current expression tree in the @a context using the
  /// designed @a format.
  virtual void print (Expression_Tree_Context &context,
                      const std::string &format);

  /// Evaluate the yield of the current expression tree in the @a
  /// context using the designed @a format.
  virtual void evaluate (Expression_Tree_Context &context,
                         const std::string &format);
};

/**
 * @class Post_Order_Uninitialized_State
 * @brief Now that the user has provided a format command
 *        indicating "post-order" input this state will interpret the 
 *        subsequent expression accordingly.
 */
class Post_Order_Uninitialized_State : public Uninitialized_State
{
public:
  /// Process the @a expression using a post-order interpreter and
  /// update the state of the @a context to the @a
  /// Post_Order_Initialized_State.  
  virtual void make_tree (Expression_Tree_Context &context,
                          const std::string &expression);
};

/**
 * @class Post_Order_Initialized_State
 * @brief Now that the user has provided a expr command this state
 *        will print or evaluate the subsequent expression
 *        accordingly. 
 */
class Post_Order_Initialized_State : public Post_Order_Uninitialized_State
{
public:
  /// Print the current expression tree in the @a context using the
  /// designed @a format.
  virtual void print (Expression_Tree_Context &context,
                      const std::string &format);

  /// Evaluate the yield of the current expression tree in the @a
  /// context using the designed @a format.
  virtual void evaluate (Expression_Tree_Context &context,
                         const std::string &format);
};

/**
 * @class In_Order_Uninitialized_State
 * @brief Now that the user has provided a format command
 *        indicating "in-order" input this state will interpret the 
 *        subsequent expression accordingly.
 */
class In_Order_Uninitialized_State : public Uninitialized_State
{
public:
  /// Process the @a expression using an in-order interpreter and
  /// update the state of the @a context to the @a
  /// In_Order_Initialized_State.  
  virtual void make_tree (Expression_Tree_Context &context,
                          const std::string &expression);
};

/**
 * @class In_Order_Initialized_State
 * @brief Now that the user has provided a expr command this state
 *        will print or evaluate the subsequent expression
 *        accordingly. 
 */
class In_Order_Initialized_State : public In_Order_Uninitialized_State
{
public:
  /// Print the current expression tree in the @a context using the
  /// designed @a format.
  virtual void print (Expression_Tree_Context &context,
                      const std::string &format);

  /// Evaluate the yield of the current expression tree in the @a
  /// context using the designed @a format.
  virtual void evaluate (Expression_Tree_Context &context,
                         const std::string &format);
};

/**
 * @class Level_Order_Uninitialized_State
 * @brief Now that the user has provided a format command
 *        indicating "level-order" input this state will interpret the 
 *        subsequent expression accordingly.
 */
class Level_Order_Uninitialized_State : public Uninitialized_State
{
public:
  /// Process the @a expression using a level-order interpreter and
  /// update the state of the @a context to the @a
  /// Level_Order_Initialized_State.  
  virtual void make_tree (Expression_Tree_Context &context,
                          const std::string &expression);
};

/**
 * @class Level_Order_Initialized_State
 * @brief Now that the user has provided a expr command this state
 *        will print or evaluate the subsequent expression
 *        accordingly. 
 */
class Level_Order_Initialized_State : public Level_Order_Uninitialized_State
{
public:
  /// Print the current expression tree in the @a context using the
  /// designed @a format.
  virtual void print (Expression_Tree_Context &context,
                      const std::string &format);

  /// Evaluate the yield of the current expression tree in the @a
  /// context using the designed @a format.
  virtual void evaluate (Expression_Tree_Context &context,
                         const std::string &format);
};

#endif /* TREE_STATE_H_ */
