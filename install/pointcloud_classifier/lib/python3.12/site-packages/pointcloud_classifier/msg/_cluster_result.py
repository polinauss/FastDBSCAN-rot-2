# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pointcloud_classifier:msg/ClusterResult.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ClusterResult(type):
    """Metaclass of message 'ClusterResult'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('pointcloud_classifier')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'pointcloud_classifier.msg.ClusterResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cluster_result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cluster_result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cluster_result
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cluster_result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cluster_result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ClusterResult(metaclass=Metaclass_ClusterResult):
    """Message class 'ClusterResult'."""

    __slots__ = [
        '_id',
        '_type_name',
        '_type_code',
        '_center_x',
        '_center_y',
        '_center_z',
        '_num_points',
        '_width',
        '_height',
        '_depth',
        '_density',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'id': 'int32',
        'type_name': 'string',
        'type_code': 'int32',
        'center_x': 'float',
        'center_y': 'float',
        'center_z': 'float',
        'num_points': 'int32',
        'width': 'float',
        'height': 'float',
        'depth': 'float',
        'density': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get('id', int())
        self.type_name = kwargs.get('type_name', str())
        self.type_code = kwargs.get('type_code', int())
        self.center_x = kwargs.get('center_x', float())
        self.center_y = kwargs.get('center_y', float())
        self.center_z = kwargs.get('center_z', float())
        self.num_points = kwargs.get('num_points', int())
        self.width = kwargs.get('width', float())
        self.height = kwargs.get('height', float())
        self.depth = kwargs.get('depth', float())
        self.density = kwargs.get('density', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.id != other.id:
            return False
        if self.type_name != other.type_name:
            return False
        if self.type_code != other.type_code:
            return False
        if self.center_x != other.center_x:
            return False
        if self.center_y != other.center_y:
            return False
        if self.center_z != other.center_z:
            return False
        if self.num_points != other.num_points:
            return False
        if self.width != other.width:
            return False
        if self.height != other.height:
            return False
        if self.depth != other.depth:
            return False
        if self.density != other.density:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'id' field must be an integer in [-2147483648, 2147483647]"
        self._id = value

    @builtins.property
    def type_name(self):
        """Message field 'type_name'."""
        return self._type_name

    @type_name.setter
    def type_name(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'type_name' field must be of type 'str'"
        self._type_name = value

    @builtins.property
    def type_code(self):
        """Message field 'type_code'."""
        return self._type_code

    @type_code.setter
    def type_code(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'type_code' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'type_code' field must be an integer in [-2147483648, 2147483647]"
        self._type_code = value

    @builtins.property
    def center_x(self):
        """Message field 'center_x'."""
        return self._center_x

    @center_x.setter
    def center_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'center_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'center_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._center_x = value

    @builtins.property
    def center_y(self):
        """Message field 'center_y'."""
        return self._center_y

    @center_y.setter
    def center_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'center_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'center_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._center_y = value

    @builtins.property
    def center_z(self):
        """Message field 'center_z'."""
        return self._center_z

    @center_z.setter
    def center_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'center_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'center_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._center_z = value

    @builtins.property
    def num_points(self):
        """Message field 'num_points'."""
        return self._num_points

    @num_points.setter
    def num_points(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'num_points' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'num_points' field must be an integer in [-2147483648, 2147483647]"
        self._num_points = value

    @builtins.property
    def width(self):
        """Message field 'width'."""
        return self._width

    @width.setter
    def width(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'width' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'width' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._width = value

    @builtins.property
    def height(self):
        """Message field 'height'."""
        return self._height

    @height.setter
    def height(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'height' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'height' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._height = value

    @builtins.property
    def depth(self):
        """Message field 'depth'."""
        return self._depth

    @depth.setter
    def depth(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'depth' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'depth' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._depth = value

    @builtins.property
    def density(self):
        """Message field 'density'."""
        return self._density

    @density.setter
    def density(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'density' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'density' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._density = value
